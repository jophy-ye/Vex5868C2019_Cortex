/**
 * Standard functions and typedefs for Vector 2d
 */

#include "vector2d.h"
#include <math.h>

inline void vector2d_set_x(vector2d* vector2d_input, double x_input)
{ vector2d_input->x = x_input; }

inline void vector2d_set_y(vector2d* vector2d_input, double y_input)
{ vector2d_input->y = y_input; }

inline double vector2d_get_x(vector2d* vector2d_input)
{ return vector2d_input->x; }

inline double vector2d_get_y(vector2d* vector2d_input)
{ return vector2d_input->y; }

inline double vector2d_get_magnitude(vector2d* vector2d_input)
{
    return sqrt(vector2d_input->x * vector2d_input->x + vector2d_input->y * vector2d_input->y);
}

double vector2d_get_gradient(vector2d* vector2d_input)
{
    if (vector2d_input->y == 0)
        return 99999999999; // something we pretend to be inf
    else
        return vector2d_input->x / vector2d_input->y;
}