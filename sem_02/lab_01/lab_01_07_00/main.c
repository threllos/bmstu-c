#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double s(double x, double eps)
{
    double frac_up, frac_down, frac;
    double result = 1;
    int i = 1;

    frac_up = x;
    frac_down = 1.0;
    frac = frac_up / frac_down;

    while (fabs(frac) > eps)
    {
        result += frac;
        frac_up *= x;
        i += 1;
        frac_down *= i;
        frac = frac_up / frac_down;
    }

    return result;
}

int main(void)
{
    double x, eps;
    double s_value, f_value;
    double delta, beta;

    printf("Input x: ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }

    printf("Input eps: ");
    if ((scanf("%lf", &eps) != 1) || (eps > 1 || eps <= 0))
    {
        printf("Input error");
        return EXIT_FAILURE;
    }

    s_value = s(x, eps);
    f_value = exp(x);
    delta = fabs(f_value - s_value);
    beta = delta / fabs(f_value);

    printf("f is %.6lf\n", f_value);
    printf("s is %.6lf\n", s_value);
    printf("delta is %.6lf\n", delta);
    printf("beta is %.6lf\n", beta);

    return EXIT_SUCCESS;
}