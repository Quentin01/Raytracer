#define _USE_MATH_DEFINES
#include <cmath>

#include "config.hh"

#define EQN_EPSILON     1e-90

#define IS_ZERO(x)      ((x) > -EQN_EPSILON && (x) < EQN_EPSILON)
#define CBRT(x)         ((x) > 0.0 ? pow((DOUBLE)(x), 1.0 / 3.0) : \
                        ((x) < 0.0 ? -pow((DOUBLE)-(x), 1.0 / 3.0) : 0.0))

namespace Math
{
    unsigned int solveQuadric(DOUBLE coeffs[3], DOUBLE roots[2]);
    unsigned int solveCubic(DOUBLE coeffs[4], DOUBLE roots[3]);
    unsigned int solveQuartic(DOUBLE coeffs[5], DOUBLE roots[4]);
};