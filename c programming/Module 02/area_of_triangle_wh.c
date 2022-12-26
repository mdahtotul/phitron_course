#include <stdio.h>

int main()
{

    float width, height, area;

    printf("Enter the width of a triangle ~ ");
    scanf("%f", &width);

    printf("Enter the height of a triangle ~ ");
    scanf("%f", &height);

    area = 0.5 * width * height;
    printf("The area of that triangle is %f", area);

    return 0;
}
