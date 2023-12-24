#include <stdio.h>
#include <stdlib.h>
void printbin(int);
void printbinloop(int);
void printhexa(int);
void printhexaloop(int);
int printpower(int,int);
void main()
{
   int x ;
   int power;
   int calculated_power;
   printf("Please enter the base number\n");
   scanf("%d",&x);
   printf("Please enter the power\n");
   scanf("%d",&power);
   calculated_power=printpower(x,power);
   printf("%d",calculated_power);

  // printf("Please enter a number\n");

   //scanf("%d", &x);
  // printf("The binary of the entered number is \n");
  // printbin(x); // recursive binary
   //printbinloop(x); //loop binary
  //printf("The hexa of the entered number is \n");
  // printhexa(x);  //recursive hexa
   //printhexaloop(x); // loop hexa
}
void printbin(int n) //recursive function binary
{
    int div, rem;
    div= n/2;
    rem= n%2;

  if (div !=0)
    {
        printbin(div);
    }
    printf("%d",rem);

}
void printbinloop(int n) //binary with loop
{
    int div, rem;
    do{
        div= n/2;
        rem= n%2;
        printf("%d",rem);
        n=div;
    }
    while(div !=0);
}
void printhexa(int n) //recursive function hexadecimal
{
    int div, rem;
    div= n/16;
    rem= n%16;
    if(div !=0)
    {
        printhexa(div);
    }
    switch(rem)
    {
     case 10:
        {
            rem='A';
             printf("%c",rem);
            break;
        }
         case 11:
        {
            rem='B';
             printf("%c",rem);
            break;
        }
         case 12:
        {
            rem='C';
             printf("%c",rem);
            break;
        }
         case 13:
        {
            rem='D';
             printf("%c",rem);
            break;
        }
         case 14:
        {
            rem='E';
             printf("%c",rem);
            break;
        }
         case 15:
        {
            rem='F';
             printf("%c",rem);
            break;
        }
         default:
             printf("%d",rem);
    }
}
void printhexaloop(int n)// hexadecimal with loop
{
     int div, rem;
     do
     {
         div= n/16;
         rem= n%16;
         switch(rem)
    {
     case 10:
        {
            rem='A';
             printf("%c",rem);
            break;
        }
         case 11:
        {
            rem='B';
             printf("%c",rem);
            break;
        }
         case 12:
        {
            rem='C';
             printf("%c",rem);
            break;
        }
         case 13:
        {
            rem='D';
             printf("%c",rem);
            break;
        }
         case 14:
        {
            rem='E';
             printf("%c",rem);
            break;
        }
         case 15:
        {
            rem='F';
             printf("%c",rem);
            break;
        }
         default:
             printf("%d",rem);
    }
          n=div;
     }while(div !=0);
}
int printpower(int n, int p)

{
if (p ==0)
    return 1;
else {
    return n *printpower(n,p-1);
}
}
