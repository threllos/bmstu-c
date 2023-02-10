#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double a, b;
    double c;
    double height;
    double perimeter;
	
    setbuf(stdout, NULL);

    printf("Input a, b: ");
    scanf("%lf%lf", &a, &b);
    printf("Input height: ");
    scanf("%lf", &height);

    c = sqrt(((b - a) * (b - a) / 4.0) + height * height);
    perimeter = 2 * c + a + b;
    printf("perimeter is %.6lf\n", perimeter);

    return EXIT_SUCCESS;
}
