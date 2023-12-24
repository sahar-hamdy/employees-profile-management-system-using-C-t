#include <stdio.h>
#include <stdlib.h>

int main()
{
    char key;
    while (key!=27)
    {
        printf("press any key \n");
        key=getch();
        if(key==-32)
        {
            printf("\n key is extended key ");
            key=getch();
            printf("with ASCI code: %d \n",key);
        }else
        printf("\n key is normal key with ASCI code: %d \n",key);
    }
    return 0;
}
