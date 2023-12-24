#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define USR 3

int main()
{
    char fname[USR][11];
    char lname[USR][11];
    char fullname[USR][22];
    int i;
    // fill names
    for (i=0;i<USR;i++)
    {
        gets(fname[i]);
        gets(lname[i]);
    }
    //concatenate process
    for(i=0;i<USR;i++)
    {
        strcpy(fullname[i],fname[i]);
        strcat(fullname[i]," ");
        strcat(fullname[i],lname[i]);
    }
    for(i=0;i<USR;i++)
    {
        printf("\n user full name is: %s ",fullname[i]);
    }


    return 0;
}
