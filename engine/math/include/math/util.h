#ifndef MATH_UTIL_H
#define MATH_UTIL_H

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MIN3(a, b, c) (MIN(MIN(a, b), c))
#define MAX3(a, b, c) (MAX(MAX(a, b), c))

#define PI 3.14159265f
#define HALF_PI (PI / 2.f)
#define TWO_PI (PI * 2.f)

#endif
