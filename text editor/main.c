#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

char *text_editor(int,int,int);
void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void clrscr(){
system("cls");
}
void textattr(int ForgC) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, ForgC);
}
char* text_editor(int size,int col, int row)
{
    for(int i=0; i<size; i++)
    {
        gotoxy(col+i,row);
        textattr(0x60);
        _cprintf(" ");
    }
    char *arr, *pcurr, *plast, *pfirst;
    pcurr=plast=pfirst=arr;
    int current,last,first;
    current=last=first=col;
    char ch;
    do
    {
        gotoxy(current,row);
        ch=getchar();
        switch(ch)
        {
        case -32:
            ch=getchar();
            switch(ch)
            {
            case 72:
                if(current>last)
                    {current=last;}
                current++;
                pcurr++;

                break;
            case 80:
                if (current<first)
                    current=first;
                current--;
                pcurr--;

                break;

            case 75:
                pcurr=pfirst;
                current=first;
                break;
            case 77:
                gotoxy(last,row);
                pcurr=plast;
                current=last;
                break;
            case 8:
                if(current>0)
                current--;
                pcurr--;
                for(int i=0;i<current;i++){
                    arr[i]=arr[i+1];
                }
                last--;
                break;
            }
            default:
                if(isprint(ch)){
                printf("%c",ch);
                current++;
                last++;
                pcurr++;
                plast++; }
                break;


            }


        }while(1);
   return arr;
}



int main()
{
text_editor(50,40,17);
    return 0;
}
