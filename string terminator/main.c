#include <stdio.h>
#include <stdlib.h>

int main()
{
   char text[10];
   int i=0;
    while(1)
    {
        char ch=getchar();
        if(ch=='/n' || i==9)
           {
                text[i]='\0';
                break;

    }
           text[i] =ch;
           i++;

    }
    printf("\n your text is:%s",text);
    return 0;
}
