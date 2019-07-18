#ifndef _VECTOR_2D_H_
#define _VECTOR_2D_H_


/**
 * Standard functions and typedefs for Vector 2d
 */

typedef struct {
    double x, y;
} vector2d;


inline void vector2d_set_x(vector2d* vector2d_input, double x_input);

inline void vector2d_set_y(vector2d* vector2d_input, double y_input);

inline double vector2d_get_x(vector2d* vector2d_input);

inline double vector2d_get_y(vector2d* vector2d_input);

inline double vector2d_get_magnitude(vector2d* vector2d_input);

double vector2d_get_gradient(vector2d* vector2d_input);


#endif