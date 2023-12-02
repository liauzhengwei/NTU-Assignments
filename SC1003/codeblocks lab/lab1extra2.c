#include <stdio.h>
int main()
{
    int i,d=1;
    float x, b=1.0,n=1.0;
    printf("Enter x: \n");
    scanf("%f", &x);

    for (i = 1; i <= 10; i++)
    {
        d *= i;
        n *= x;

        b += n/d;
    }

    printf("%.2f",b);

    return 0;
}
