#include "/home/bellon/the-maze/headers/header.h"
/**
 * SDL_KEYDOWN_FUNC - process input when a key is down
 * @event: union that contains structures for the different event types
*/

void SDL_KEYDOWN_FUNC(SDL_Event event)
{if (event.key.keysym.sym == SDLK_ESCAPE)
		GameRunning = false;
	if (event.key.keysym.sym == SDLK_UP)
		player.walkDirection = +1;
	if (event.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = -1;
	if (event.key.keysym.sym == SDLK_RIGHT)
		player.turnDirection = +1;
	if (event.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = -1;
	if (event.key.keysym.sym == SDLK_w)
		player.walkDirection = +1;
	if (event.key.keysym.sym == SDLK_s)
		player.walkDirection = -1;
	if (event.key.keysym.sym == SDLK_a)
		player.turnDirection = -1;
	if (event.key.keysym.sym == SDLK_d)
		player.turnDirection = +1;
}
