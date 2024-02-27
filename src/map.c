#include "../headers/header.h"

static const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6},
    {6, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 6, 0, 7, 7, 0, 0, 0, 0, 6},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 7, 0, 6},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 6},
    {6, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 1, 0, 0, 0, 0, 7, 7, 0, 6},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
    {6, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
    {6, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}
};

/**
 * Detects potential collision with the wall in the next player movement.
 *
 * @x: Next x coordinate.
 * @y: Next y coordinate.
 * 
 * @return: True if collision is detected, false otherwise.
 */
bool DetectCollision(float x, float y)
{
    int mapGridX, mapGridY;

    if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE ||
        y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE)
        return true;

    mapGridX = floor(x / TILE_SIZE);
    mapGridY = floor(y / TILE_SIZE);
    return (map[mapGridY][mapGridX] != 0);
}

/**
 * Checks if the coordinates are within the map boundaries.
 *
 * @x: X coordinate.
 * @y: Y coordinate.
 * 
 * @return: True if coordinates are within the map, false otherwise.
 */
bool isInsideMap(float x, float y)
{
    return (x >= 0 && x <= MAP_NUM_COLS * TILE_SIZE &&
            y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}

/**
 * Retrieves the value at the specified position in the map.
 *
 * @row: Row index.
 * @col: Column index.
 * 
 * @return: The value at the specified position in the map.
 */
int getMapValue(int row, int col)
{
    return map[row][col];
}

/**
 * Renders the map.
 */
void renderMap(void)
{
    int i, j, tileX, tileY;
    color_t tileColor;

    for (i = 0; i < MAP_NUM_ROWS; i++)
    {
        for (j = 0; j < MAP_NUM_COLS; j++)
        {
            tileX = j * TILE_SIZE;
            tileY = i * TILE_SIZE;
            tileColor = map[i][j] != 0 ? 0xFFFFFFFF : 0x00000000;

            drawRect(
                tileX * MINIMAP_SCALE_FACTOR,
                tileY * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR,
                tileColor
            );
        }
    }
}
