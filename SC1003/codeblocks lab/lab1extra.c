#include <stdio.h>
int main()
{
    int height, a,b, i;
    printf("Enter a height: \n");
    scanf("%d", &height);

    for (i = 1; i <= height; i++)
    {
        for (b = 1; b<=i ;b++)
        {
            a = i%3;
            if(a == 0)
            {
                a = 3;
            }
            printf("%d",a);
        }
        printf("\n");
    }
    return 0;
}
