#include <stdio.h>
#include <stdlib.h>
#define STD 4
#define COR 5

int main()
{
    float marks[STD][COR];
    float total,sum,avg;
    int i,j;
    // to input the grades
    for(i=0;i<STD;i++)
    {
        printf("student %d \n",i+1);
        for(j=0;j<COR;j++)
        {
            printf("Grade %d ",j+1);
            scanf("%f",&marks[i][j]);
        }
    }
    //to calculate the total grades
    float totalscore[STD];
    for (i=0;i<STD;i++)
    { total=0.0;
        for (j=0;j<COR;j++)
        {
            total+=marks[i][j];
            totalscore[i]=total;
        }
        printf(" \n total grades are %f for student: %d \n",total, i+1);
    }

    //student with highest total
    float highscore=totalscore[0];
    for (i=0;i<STD;i++)
    {
         if (totalscore[1]>highscore)
            highscore=totalscore[i];
        }
        printf(" \n %f highest score\n",total, i+1,highscore);
        // to calculate the average
     for(j=0;j<COR;j++)
        {
     for (i=0;i<STD;i++)
     {
          sum+=marks[i][j];
         }
         avg=sum/STD;
         printf("\n average of grades %d  is:%f \n",j+1,avg);
        }

   /* floats grade1,grade2,grade3;
   printf("please enter course1 grade \n");
   scanf("%f",&grade1);
    if (grade1>=0&&grade1<=100)
        printf("grade1 is:%f \n",grade1);
        else
        {
         printf("enter valid grade between 0 and 100 \n");
            scanf("%f",&grade1);
        }

    printf("please enter course2 grade \n");
    scanf("%f",&grade2);
    if (grade2>=0&&grade2<=100)
        printf("grade2 is:%f \n",grade2);
         else
         {
             printf("enter valid grade between 0 and 100 \n");
             scanf("%f",&grade2);
         }

    printf("please enter course3 grade \n");
    scanf("%f",&grade3);
    if (grade3>=0&&grade3<=100)
        printf("grade3 is:%f \n",grade3);
        else
        {
             printf("enter valid grade between 0 and 100 \n ");
             scanf("%f",&grade3);
        }

    sum= (grade1+grade2+grade3)/3;
    printf("total is: %f\n",sum);
    if (sum<=100&&sum>=85)
        printf(" your grade is:A");
    else
        if (sum<85&&sum>=75)
            printf(" your grade is:B \n");
            else
                if (sum<75&&sum>=65)
                    printf("your grade is:C \n");
                    else
                        if (sum<65&&sum>=60)
                           printf("your grade is:D \n");
                           else
                           if (sum<60)
                               printf("your grade is:F \n");
                               else
                               printf("your grade is not avialbe \n"); */

    return 0;
}
