#include <stdio.h>
#include <conio.h>
#define NUM_OPTIONS 3
#define RESET_COLOR "\x1B[0m" //white ANSI
#define HIGHLIGHT_COLOR "\x1b[103m" //magenta

int main() {
    int option = 0;
    char menu[3][10] = {"New","Display","Exit"};
    int page = 3;
    while (1) {
        system("cls");
        printf(RESET_COLOR);
        if(page==3){       //3=main menu
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
        if (key == 13) {
            page = option;
        }
    }
    else if(page == 0){
        printf(RESET_COLOR);
        printf("New:\n");
        printf("This is a new display:\n");
        printf(HIGHLIGHT_COLOR);
        printf("Press ESC to return to previous menu\n");
        char key = getch();
        if(key == 27){
            page = 3;
        }
    }
    else if(page == 1){
        printf(RESET_COLOR);
        printf("Display:\n");
        printf("This is a Dsiplay display:\n");
        printf(HIGHLIGHT_COLOR);
        printf("Press ESC to return to previous menu\n");
        char key = getch();
        if(key == 27){
            page = 3;
        }
    }
    else if(page==2||page==4){
        printf("Good bye");
        break;
    }
    }
    return 0;
}
