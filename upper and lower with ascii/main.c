#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[10];
    int i;
    char choice;
    puts("enter your text");
    gets(text);
    printf("\n a- upper case \n");
    printf("\n b- lower case \n");
    choice=getch();

    switch(choice)
    {
        //convert to upper case
    case 'A':
    case 'a':
    {
         for(i=0;i<5;i++)
    {
        if (97<=text[i]&&text[i]<=122)
    {
        text[i]=text[i]-32;
    }
    }
    printf("\n your upper text is: %s",text);
    break;
    }

    //convert to lower case
    case 'B':
    case 'b':
        {
             for(i=0;i<5;i++)
    {
        if (65<=text[i]&&text[i]<=90)
    {
        text[i]=text[i]+32;

    }
    }
    printf("\n your lower text is: %s",text);
    break;
        }
    default:
    printf("\n please enter a valid choice \n");

    }





    return 0;
}
