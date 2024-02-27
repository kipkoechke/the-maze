#include "../headers/header.h"

static SDL_Renderer *renderer;
static color_t *colorBuffer;
static SDL_Texture *colorBufferTexture;
static SDL_Window *window;

/**
 * Initializes the window for displaying the maze.
 * 
 * @return: True if initialization is successful, false otherwise.
 */
bool initializeWindow(void)
{
    SDL_DisplayMode display_mode;
    int fullScreenWidth, fullScreenHeight;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return false;
    }
    SDL_GetCurrentDisplayMode(0, &display_mode);
    fullScreenWidth = display_mode.w;
    fullScreenHeight = display_mode.h;
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        fullScreenWidth,
        fullScreenHeight,
        SDL_WINDOW_BORDERLESS
    );
    if (!window)
    {
        fprintf(stderr, "Error creating SDL window.\n");
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 1);
    if (!renderer)
    {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return false;
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    /* Allocate memory for the color buffer */
    colorBuffer = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);

    /* Create an SDL_Texture to display the color buffer */
    colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32,
                                           SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

    return true;
}

/**
 * Destroys the window when the game is over.
 */
void destroyWindow(void)
{
    free(colorBuffer);
    SDL_DestroyTexture(colorBufferTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 * Clears the color buffer for every frame.
 * 
 * @param color: The color to clear the buffer with.
 */
void clearColorBuffer(color_t color)
{
    int i;

    for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
        colorBuffer[i] = color;
}

/**
 * Renders the color buffer for every frame.
 */
void renderColorBuffer(void)
{
    SDL_UpdateTexture(
        colorBufferTexture,
        NULL,
        colorBuffer,
        (int)(SCREEN_WIDTH * sizeof(color_t))
    );
    SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

/**
 * Draws a pixel with a specified color at given coordinates.
 * 
 * @param x: The x coordinate of the pixel.
 * @param y: The y coordinate of the pixel.
 * @param color: The color of the pixel.
 */
void drawPixel(int x, int y, color_t color)
{
    colorBuffer[(SCREEN_WIDTH * y) + x] = color;
}
