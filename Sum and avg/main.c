#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a, b, sum;
   float avg;
   printf("please enter a\n");
   scanf("%d",&a);
   printf("please enter b\n");
   scanf("%d",&b);
   sum=a+b;
   printf("sum of a and b is:%d \n",sum);
   avg =(float)sum/2;
   printf("avg of a and b is:%f \n",avg);
    return 0;
}
