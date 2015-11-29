#include "Utils/Math.hh"

unsigned int Math::solveQuadric(DOUBLE coeffs[3], DOUBLE roots[2])
{
    /* x^2 + px + q = 0 */

    DOUBLE  p = coeffs[1] / (2.0 * coeffs[2]);
    DOUBLE  q = coeffs[0] / coeffs[2];

    DOUBLE  delta = p * p - q;

    if (IS_ZERO(delta))
    {
        roots[0] = -p;
        return (1);
    }
    else if (delta > 0.0)
    {
        DOUBLE  sqrt_delta = sqrt(delta);

        roots[0] = sqrt_delta - p;
        roots[1] = -sqrt_delta - p;

        return (2);
    }

    return (0);
}

unsigned int Math::solveCubic(DOUBLE coeffs[4], DOUBLE roots[3])
{
    unsigned int    nb = 0;

    /* x^3 + A * x^2 + B * x + C = 0 */

    DOUBLE  A = coeffs[2] / coeffs[3];
    DOUBLE  B = coeffs[1] / coeffs[3];
    DOUBLE  C = coeffs[0] / coeffs[3];

    /* transform to x^3 + p * x + q = 0 */

    DOUBLE  sqrd_A = A * A;
    DOUBLE  p = 1.0 / 3.0 * (-1.0 / 3.0 * sqrd_A + B);
    DOUBLE  q = 1.0 / 2.0 * (2.0 / 27.0 * A * sqrd_A - 1.0 / 3.0 * A * B + C);

    /* use Cardano's formula */

    DOUBLE  cardano_p = p * p * p;
    DOUBLE  delta = q * q + cardano_p;

    if (IS_ZERO(delta))
    {
        if (IS_ZERO(q))
        {
            roots[0] = 0;
            nb = 1;
        }
        else
        {
            DOUBLE  u = CBRT(-q);

            roots[0] = 2 * u;
            roots[1] = -u;
            nb = 2;
        }
    }
    else if (delta < 0.0)
    {
        DOUBLE  phi = 1.0 / 3.0 * acos(-q / sqrt(-cardano_p));
        DOUBLE  t = 2.0 * sqrt(-p);

        roots[0] = t * cos(phi);
        roots[1] = -t * cos(phi + M_PI / 3);
        roots[2] = -t * cos(phi - M_PI / 3);
        nb = 3;
    }
    else
    {
        DOUBLE  sqrt_delta = sqrt(delta);

        roots[0] = cbrt(sqrt_delta - q) - cbrt(sqrt_delta + q);
        nb = 1;
    }

    /* retransform to original equation */

    for (unsigned int i = 0; i < nb; i++)
        roots[i] -= 1.0 / 3.0 * A;
    
    return (nb);
}

unsigned int Math::solveQuartic(DOUBLE coeffs[5], DOUBLE roots[4])
{
    DOUBLE          new_coeffs[4];
    unsigned int    nb = 0;

    /* x^4 + A * x^3 + B * x^2 + C * x + D = 0 */

    DOUBLE  A = coeffs[3] / coeffs[4];
    DOUBLE  B = coeffs[2] / coeffs[4];
    DOUBLE  C = coeffs[1] / coeffs[4];
    DOUBLE  D = coeffs[0] / coeffs[4];
    
    /* transform to x^4 + p * x^2 + q * x + r = 0 */

    DOUBLE  sqrd_A = A * A;
    DOUBLE  p = -3.0 / 8.0 * sqrd_A + B;
    DOUBLE  q = 1.0 / 8.0 * sqrd_A * A - 1.0 / 2.0 * A * B + C;
    DOUBLE  r = -3.0 / 256.0 * sqrd_A * sqrd_A + 1.0 / 16.0 * sqrd_A * B - 1.0 / 4.0 * A * C + D;

    if (IS_ZERO(r))
    {
        new_coeffs[0] = q;
        new_coeffs[1] = p;
        new_coeffs[2] = 0;
        new_coeffs[3] = 1;

        nb = Math::solveCubic(new_coeffs, roots);

        roots[nb++] = 0;
    }
    else
    {
        new_coeffs[ 0 ] = 1.0 / 2.0 * r * p - 1.0 / 8.0 * q * q;
        new_coeffs[ 1 ] = -r;
        new_coeffs[ 2 ] = -1.0 / 2.0 * p;
        new_coeffs[ 3 ] = 1.0;

        Math::solveCubic(new_coeffs, roots);

        DOUBLE  z = roots[0];
        DOUBLE  u = z * z - r;
        DOUBLE  v = 2.0 * z - p;

        if (IS_ZERO(u))
            u = 0.0;
        else if (u > 0.0)
            u = sqrt(u);
        else
            return (0);

        if (IS_ZERO(v))
            v = 0.0;
        else if (v > 0.0)
            v = sqrt(v);
        else
            return (0);

        new_coeffs[0] = z - u;
        new_coeffs[1] = q < 0.0 ? -v : v;
        new_coeffs[2] = 1.0;

        nb = Math::solveQuadric(new_coeffs, roots);

        new_coeffs[0] = z + u;
        new_coeffs[1] = q < 0.0 ? v : -v;
        new_coeffs[2] = 1.0;

        nb += Math::solveQuadric(new_coeffs, roots + nb);
    }

    /* retransform to original equation */

    for (unsigned int i = 0; i < nb; i++)
        roots[i] -= 1.0 / 4.0 * A;

    return (nb);
}