#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lineno = 0,line,t,result,count;
    double avg;
    printf("Enter number of lines: \n");
    scanf("%d",&lineno);

    for (t=1; t<=lineno; t++)
    {
        count = 0;result = 0;
        printf("Enter line %d(end with -1):\n",t);
        scanf("%d",&line);
        while (line != -1){
            result += line;
            count +=1;
            scanf("%d",&line);
        }
        avg = (double)result/(double)count;
        printf("Average = %.2f\n",avg);
    }
    return 0;
}
