#include "../headers/header.h"

/**
 * Calculates the distance between two points.
 * 
 * @param x1: x coordinate of the starting point.
 * @param y1: y coordinate of the starting point.
 * @param x2: x coordinate of the end point.
 * @param y2: y coordinate of the end point.
 * @return: The distance between two points.
 */
float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

/**
 * Checks if the ray is facing downwards.
 * 
 * @param angle: The current ray angle.
 * @return: True if the ray is facing down, false otherwise.
 */
bool isRayFacingDown(float angle)
{
    return (angle > 0 && angle < PI);
}

/**
 * Checks if the ray is facing upwards.
 * 
 * @param angle: The current ray angle.
 * @return: True if the ray is facing up, false otherwise.
 */
bool isRayFacingUp(float angle)
{
    return (!isRayFacingDown(angle));
}

/**
 * Checks if the ray is facing to the right.
 * 
 * @param angle: The current ray angle.
 * @return: True if the ray is facing right, false otherwise.
 */
bool isRayFacingRight(float angle)
{
    return (angle < 0.5 * PI || angle > 1.5 * PI);
}

/**
 * Checks if the ray is facing to the left.
 * 
 * @param angle: The current ray angle.
 * @return: True if the ray is facing left, false otherwise.
 */
bool isRayFacingLeft(float angle)
{
    return (!isRayFacingRight(angle));
}
