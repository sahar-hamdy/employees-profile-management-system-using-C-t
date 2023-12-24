#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

int main()
{
   char text[SIZE][20];
   int i;
   int len;
   int largest;
   int shortest;
   // enter text
   for(i=0;i<SIZE;i++)
   {
       puts("please enter your text \n");
       gets(text[i]);
       len=strlen(text[i]);
       printf("your text lenght is : %d \n",len);

   }
   //calculate largest and shortest
   largest=0; //position of largest
   shortest=0;  //position of shortest
   for(i=1;i<SIZE;i++)
   {
    if(text[i]>text[largest])
        largest=i;
    if(text[i]<text[shortest])
        shortest=i;
   }
   printf("largest text is %s in %d \n",text[largest],largest);
   printf("shortest text is %s in %d \n",text[shortest],shortest);

    return 0;
}
