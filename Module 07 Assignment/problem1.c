#include <stdio.h>

int main()
{
    int a=5, b=13, temp;
    //Write code here
    temp = b;
    b =  a;
    a = temp;

    //End of code
    printf("%d and %d" , a, b);

    return 0;
}
