#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9

double power(double x, int n)
{
    double result = 1;
    if (n > 0)
        for (int i = 0; i < n; i++)
            result *= x;
    else if (n < 0)
        for (int i = 0; i > n; i--)
            result /= x;
    return result;
}

double f(double x)
{
	double result;
    result = -1.0 / power(x, 5) * exp(-x * x * x) * (1 + x) * (1 - x + x * x);
	return result;
}

double s(double x, double eps)
{
    double result = 0.0;
    int i = 0;
    double current = x / 2;

    while (fabs(current) >= eps)
	{
        result += current;
        i += 1;
        current *= -x * x * x * (1 + i) / (i * i + 2 * i);
	}
	return result;
}

int main(void)
{
    double x;
    double eps;

    printf("input x: ");
    if (scanf("%lf", &x) != 1 || fabs(x) < EPS)
    {
        printf("input x error\n");
        return EXIT_FAILURE;
    }

    printf("input eps: ");
    if (scanf("%lf", &eps) != 1 || eps <= 0)
    {
        printf("input eps error\n");
        return EXIT_FAILURE;
    }
	
	double f_result = f(x);
    printf("f is %e\n", f_result);
	
    double s_result = s(x, eps);
    printf("s is %g\n", s_result);

    return EXIT_SUCCESS;
}
