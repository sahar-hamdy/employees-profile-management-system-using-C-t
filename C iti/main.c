#include <stdio.h>
#include <stdlib.h>

int main()
{
   char x;
   int y;
    printf("Please Enter a character\n");
    scanf("%c",&x);
    printf("ascii value of x variable is :%d \n", x); //to return ascii value
    printf("Please Enter a number\n");
    scanf("%d",&y);
    printf("octal value of y is :%o \n",y); // to return octal value
    printf("hexadecimal value of y is :%x \n",y); // to return hexa value
    return 0;
}
