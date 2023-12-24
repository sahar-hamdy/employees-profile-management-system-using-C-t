#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#define NUM_OPTIONS 4
#define RESET_COLOR "\x1B[0m" //white ANSI
#define HIGHLIGHT_COLOR "\e[0;33m" //yellow
struct Employee *add_employee(int *);
struct Employee
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
struct Employee *add_employee(int *n)
{
    struct Employee *pemp,*pc;
    int i;
    printf("Please enter no. of employees: \n"); //get no. of employees from user
    scanf("%d",n);
    system("cls");
    pemp=(struct Empolyee*)malloc(sizeof(struct Employee)*(*n));
    if (!pemp)
        exit(1);


    for(pc=pemp,i=0;i<*n;i++,pc++)
    {
        system("cls");
        gotoxy(20,1);
        printf("New employee: %d\n",i+1);
        gotoxy(6,2);
        printf("code:");
        scanf("%d",&pc->code);
         gotoxy(50,2);
        printf("name:");
        scanf("%s",&pc->name);
         gotoxy(6,3);
        printf("age:");
        scanf("%d",&pc->age);
         gotoxy(50,3);
        printf("salary:");
        scanf("%f",&pc->salary);
         gotoxy(6,4);
        printf("bouns:");
        scanf("%f",&pc->bouns);
         gotoxy(50,4);
        printf("deduct:");
        scanf("%f",&pc->deduct);
        pc->netsalary = pc->salary + pc->bouns - pc->deduct;
    }

        return pemp;
}

int display_emp_by_index(bool flag, struct Employee *emp, int page, int n)
{
        if(flag){
        printf(RESET_COLOR);
        gotoxy(20,1);
        printf("please enter employee index:\n");
        while(1){
        int index;
        scanf("%d",&index);
        if(index <= n && index > -1){
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

        return page;
}
int display_all_employees(bool flag, struct Employee *emp,int page, int n)
{
    if(flag){
        printf(RESET_COLOR);
        gotoxy(20,1);
        printf("Display all employee's data:\n");
        for(int i=0;i<n;i++,emp++)
        {
             printf("employee:\t%d\n",i+1);
             printf("\n code:\t%d\n",emp->code);
             printf("name:\t%s\n",emp->name);
             printf("age:\t%d\n",emp->age);
             printf("salary\t%f\n",emp->salary);
             printf("bouns\t%f\n",emp->bouns);
             printf("deduct\t%f\n",emp->deduct);
             printf("net salary\t%f\n",emp->netsalary);
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
    return page;
}

int main_menu(int option,char menu[4][30])
{
    int page;
    page=5;
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
                    option = page + 10;
                    break;
            }
        if (key == 13) { //enter key
            option = option+10;
        }
return option;
}


int main()
{
   int *n = malloc(sizeof(int));
   int *p;
   int option = 0;
    char menu[4][30] = {"New","Display","Display All","Exit"};
    int page = 5;
    bool flag = false;
    while (1) {
        system("cls");
        printf(RESET_COLOR);
        if(page==5){       //5=main menu
        option=main_menu(option, menu);
        if(option>=10){
            page=option-10;
            option=0;
        }
    }
    else if(page == 0){//enter employee data
        printf(RESET_COLOR);
        int i;

        p = add_employee(n);
        printf("Please press ESC to return to main menu");
        char key = getch();
        if(key == 27 || i==2){
            flag = true;
            page = 5;
        }

    }
    else if(page == 1){ //dispaly page
        page=display_emp_by_index(flag, p, page, *n);
    }
    else if(page == 2){ //display all page
        page=display_all_employees(flag,p, page, *n);
        }
    else if(page==3 || page==4){// exit page
        printf("Good bye");
        free(p);
        break;
    }
    }

    return 0;
}
