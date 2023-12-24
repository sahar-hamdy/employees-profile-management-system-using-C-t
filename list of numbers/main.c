#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int sum=0;
    float avg;
    for (int i=0;i<=9;i++)
    {
        printf("\n please enter numbers \n");
        scanf("%d",&x);
        sum+=x;
    }
     printf("sum of numbers is : %d \n",sum);
     avg = (float)sum/10;
     printf("the average of numbers is: %f \n",avg);
    return 0;
}
