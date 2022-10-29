#include <stdio.h>
#include <math.h>

int main()
{

    float a, b, c, s, sa, sb, sc, half_s;

    printf("Enter 1st value of a triangle ~ ");
    scanf("%f", &a);

    printf("Enter 2nd value of a triangle ~ ");
    scanf("%f", &b);

    printf("Enter #rd value of a triangle ~ ");
    scanf("%f", &c);

    s = a + b + c;

    half_s = 0.5 * s;

    sa = s - a;
    sb = s - b;
    sc = s - c;

    double area = sqrt(s * sa * sb* sc);
    printf("The area of triangle is %f", area);

    return 0;
}
