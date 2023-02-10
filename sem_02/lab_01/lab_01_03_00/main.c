#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double height_cm, girth, weight;
    double m_normal, bmi;
    double height_m;

    setbuf(stdout, NULL);

    printf("Input height(cm): ");
    scanf("%lf", &height_cm);
    printf("Input t(cm): ");
    scanf("%lf", &girth);
    printf("Input weight(kg): ");
    scanf("%lf", &weight);

    height_m = height_cm / 100.0;
    m_normal = height_cm * girth / 240.0;
    bmi = weight / height_m / height_m;

    printf("m normal is %.6lf\n", m_normal);
    printf("BMI is %.6lf\n", bmi);

    return EXIT_SUCCESS;
}
