#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void main(void)
{
   int row, col, value, size;
   printf("please enter odd number: \n");
   scanf("%d",&size);
   if(size%2==0)
    {
        printf("size must be odd.\n");
        printf("Exiting...");
        exit(0);
    }
   row=1;
   col=(size+1)/2;
   value=1;
   COORD coord={0,0};
 void gotoxy(int x, int y)
   {

       coord.X=x;
       coord.Y=y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coord);
   }
   do {
       gotoxy(col*5,row);
       printf("%5d",value);
       if (value%size==0)
          row++;
       else
           {
             row--;
             col--;
            }
       if(row==0)
       row=size;
       if(col==0)
       col=size;
       value++;

   }while(value<=size*size);

    return 0;
}
