#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
   float numbers [SIZE];
   char choice;
   int i;
   int j;
   float sum;
   float avg;
   float asc;
   float desc;

   for(i=0;i<SIZE;i++)
   {
       printf("please enter number: %d \n", i+1);
       scanf("%f",&numbers[i]);
   }
   //menu list
   printf("a- sum \n");
   printf("b- average \n");
   printf("c- max \n");
   printf("d- min \n");
   printf("s- sort ASC \n");
   printf("f- sort DESC \n");
   printf("g- Reversed order \n");
   printf("e- exist \n");
   do
   {
   choice=getche();
   switch (choice)
   {
       case'a':
       case'A':

           for (i=0;i<SIZE-1;i++)
           {
               sum+=numbers[i];
               printf("%f+",numbers[i]);
           }
           printf("%f",numbers[SIZE-1]);
           printf("\n =%f",sum );
           break;
       case'b':
       case'B':
           {
                for (i=0;i<SIZE;i++)
                {
                   sum+=numbers[i];
                }
               avg=sum/SIZE;
               printf("\n average of numbers is:%f \n", avg);
                break;
           }
       case'c':
       case'C':
           {
               float max =numbers[0];
               for (i=0;i<SIZE;i++)
                {
                  if (numbers[i]>max)
                      max = numbers[i];
                }
                     printf(" \n the maximum number is %f \n", max);
                break;
           }
       case'd':
       case'D':
           {
               float min =numbers[0];
               for (i=0;i<SIZE;i++)
                {
                  if (numbers[i]<min)
                      min = numbers[i];
                }
                     printf(" \n the minimum number is %f \n", min);
                break;
           }
       case's':
       case'S':
           {
               for (i=0;i<SIZE;i++)
                {
                    for (j=i+1;j<SIZE;j++)
                    {
                         if (numbers[i]>numbers[j])
                         {
                              asc =numbers[i];
                              numbers[i]=numbers[j];
                              numbers[j]=asc;
                         }
                    }
                }
                for (i=0;i<SIZE;i++)
                    printf(" %f \n", numbers[i]);
             break;
           }
            case'f':
            case'F':
           {
               for (i=0;i<SIZE;i++)
                {
                    for (j=i+1;j<SIZE;j++)
                    {
                         if (numbers[i]<numbers[j])
                         {
                              desc =numbers[i];
                              numbers[i]=numbers[j];
                              numbers[j]=desc;
                         }
                    }
                }

                for (i=0;i<SIZE;i++)
                    printf(" %f \n", numbers[i]);
            break;
           }

       case'g':
       case'G':
           {
               for(i=SIZE-1;i>=0;i--)
                printf("\n %f \n",numbers[i]);
               break;
           }
       case'e':
       case'E':
           {
               exit(0);
                break;
           }
       default:
        printf("\n please enter a valid choice \n");

           }
   }while (choice != 'e');

    return 0;
}
