#include "../headers/header.h"

/**
 * drawRect - draw a rectangle
 * @x: x coordinate
 * @y: y coordinate
 * @width: rectangle width
 * @height: rectangle height
 * @color: pixel color
 */

void drawRect(int x, int y, int width, int height, color_t color)
{
  int i, j;

  for (i = x; i <= (x + width); i++)
    for (j = y; j <= (y + height); j++)
      drawPixel(i, j, color);
}
