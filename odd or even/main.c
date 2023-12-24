#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("please enter a number \n");
    scanf("%d",&x);
    if(x%2==0)
      printf("even number:%d",x);
        else
            printf("odd number:%d",x);
    return 0;
}
