#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#define NUM_OPTIONS 4
#define RESET_COLOR "\x1B[0m" //white ANSI
#define HIGHLIGHT_COLOR "\e[0;33m" //yellow
struct Empolyee
{
    int code;
    char name[20];
    int age;
    float salary;
    float bouns;
    float deduct;
    float netsalary;
};
 void gotoxy(int x, int y)
   {
      COORD coord= {0,0};
       coord.X=x;
       coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
   }

int main()
{
   struct Empolyee emp[3];
   int option = 0;
    char menu[4][30] = {"New","Display","Display All","Exit"};
    int page = 5;
    bool flag = false;
    while (1) {
        system("cls");
        printf(RESET_COLOR);
        if(page==5){       //5=main menu
        printf("Menu:\n");
        for (int i=0;i<NUM_OPTIONS;++i) {
        if (i==option) {
            printf(HIGHLIGHT_COLOR);
        }
        printf("%s\n",menu[i]);
        printf(RESET_COLOR); // Reset color after printing each option
        }
        char key = getch();
        // Check for arrow key input
            switch (key) {
                case 72: // Up arrow key
                    option = (option-1 + NUM_OPTIONS) % NUM_OPTIONS;
                    break;
                case 80: // Down arrow key
                    option = (option+1) % NUM_OPTIONS;
                    break;
                case 27:   //esc key
                    page = 4;
                    break;
            }
        if (key == 13) { //enter key
            page = option;
        }
    }
    else if(page == 0){//enter employee data
        printf(RESET_COLOR);
        int i;
        for (i=0;i<3;i++)
            {
        system("cls");
        gotoxy(20,1);
        printf("New employee: %d\n",i+1);
        gotoxy(6,2);
        printf("code:");
        scanf("%d",&emp[i].code);
         gotoxy(50,2);
        printf("name:");
        scanf("%s",&emp[i].name);
         gotoxy(6,3);
        printf("age:");
        scanf("%d",&emp[i].age);
         gotoxy(50,3);
        printf("salary:");
        scanf("%f",&emp[i].salary);
         gotoxy(6,4);
        printf("bouns:");
        scanf("%f",&emp[i].bouns);
         gotoxy(50,4);
        printf("deduct:");
        scanf("%f",&emp[i].deduct);
        emp[i].netsalary = emp[i].salary + emp[i].bouns - emp[i].deduct;
        gotoxy(50,10);
        printf("Press Enter to add new employee\n");
        gotoxy(50,12);
        printf("Press ESC to return to previous menu\n");
        char key = getch();
        if(key == 27 || i==2){
            flag = true;
            page = 5;
            break;
        }
        }

    }
    else if(page == 1){ //dispaly page
        if(flag){
        printf(RESET_COLOR);
        gotoxy(20,1);
        printf("please enter employee index:\n");
        while(1){
        int index;
        scanf("%d",&index);
        if(index <= 3 && index > -1){
            system("cls");
             gotoxy(20,1);
             printf(" employee:\t%d\n",index);
             printf("\n code:\t%d\n",emp[index].code);
             printf("name:\t%s\n",emp[index].name);
             printf("age:\t%d\n",emp[index].age);
             printf("salary\t%f\n",emp[index].salary);
             printf("bonus\t%f\n",emp[index].bouns);
             printf("deduct\t%f\n",emp[index].deduct);
             printf("net salary\t%f\n",emp[index].netsalary);
        printf("Press ESC to return to previous menu\n");
        char key = getch();
        if(key == 27){
            page = 5;
            break;
        }
        }
        else{
            printf("This employee doesn't exist, please enter a valid index\n");
        }
        }
        }
        else{
            printf("No employees available please press ESC to return to menu to add employees");
            char key = getch();
            if(key == 27){
                page=5;
            }
        }


    }
    else if(page == 2){ //display all page
        if(flag){
        printf(RESET_COLOR);
        gotoxy(20,1);
        printf("Display all employee's data:\n");
        for(int i=0;i<3;i++)
        {
             printf("employee:\t%d\n",i+1);
             printf("\n code:\t%d\n",emp[i].code);
             printf("name:\t%s\n",emp[i].name);
             printf("age:\t%d\n",emp[i].age);
             printf("salary\t%f\n",emp[i].salary);
             printf("bouns\t%f\n",emp[i].bouns);
             printf("deduct\t%f\n",emp[i].deduct);
             printf("net salary\t%f\n",emp[i].netsalary);
        }
        printf(HIGHLIGHT_COLOR);
        printf("Press ESC to return to previous menu\n");
        char key = getch();
        if(key == 27){
            page = 5;
        }
    }
    else{
        printf("No employees available please press ESC to return to menu to add employees");
            char key = getch();
            if(key == 27){
                page=5;
            }
    }
        }
    else if(page==3 || page==4){// exit page
        printf("Good bye");
        break;
    }
    }

    return 0;
}
