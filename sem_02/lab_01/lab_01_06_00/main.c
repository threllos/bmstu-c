#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-10

double length(double xi, double yi, double xj, double yj)
{
    double result;

    result = sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));

    return result;
}

double square(double xi, double yi, double xj, double yj, double xk, double yk)
{
    double result;

    result = 0.5 * fabs((xi - xk) * (yj - yk) - (xj - xk) * (yi - yk));

    return result;
}

int main(void)
{
    double xa, ya;
    double xb, yb;
    double xc, yc;
    double side_a, side_b, side_c;
    double left_eqt, right_eqt;

    setbuf(stdout, NULL);

    printf("Input coordinates a: ");
    if (scanf("%lf%lf", &xa, &ya) != 2)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }

    printf("Input coordinates b: ");
    if (scanf("%lf%lf", &xb, &yb) != 2)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }

    printf("Input coordinates c: ");
    if (scanf("%lf%lf", &xc, &yc) != 2)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }

    if (square(xa, ya, xb, yb, xc, yc) < EPS)
    {
        printf("Triangle does not exist");
        return EXIT_FAILURE;
    }

    side_a = length(xa, ya, xb, yb);
    side_b = length(xa, ya, xc, yc);
    side_c = length(xc, yc, xb, yb);

    if (side_a > side_b && side_a > side_c)
    {
        left_eqt = side_a * side_a;
        right_eqt = side_b * side_b + side_c * side_c;
    }
    else if (side_b > side_a && side_b > side_c)
    {
        left_eqt = side_b * side_b;
        right_eqt = side_a * side_a + side_c * side_c;
    }
    else
    {
        left_eqt = side_c * side_c;
        right_eqt = side_a * side_a + side_b * side_b;
    }

    if (fabs(left_eqt - right_eqt) < EPS)
        printf("Result: 1");
    else if (left_eqt < right_eqt)
        printf("Result: 0");
    else
        printf("Result: 2");

    return EXIT_SUCCESS;
}
