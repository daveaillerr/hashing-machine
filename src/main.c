#include <stdio.h>
#include <windows.h>

void greet(){
    printf("╔═════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                         ║\n");
    printf("║   ██░  ██░    ███░    ██████░  ██░  ██░  ██████░  ███░  ██░  ███████░   ║\n");
    printf("║   ██░  ██░  ██░  ██░  ██░      ██░  ██░    ██░    ████  ██░  ██░        ║\n");
    printf("║   ███████░  ███████░  ██████░  ███████░    ██░    ██░██ ██░  ██░ ███░   ║\n");
    printf("║   ██░  ██░  ██░  ██░      ██░  ██░  ██░    ██░    ██░ ████░  ██░  ██░   ║\n");
    printf("║   ██░  ██░  ██░  ██░  ██████░  ██░  ██░  ██████░  ██░   ██░  ███████░   ║\n");
    printf("║                                                                         ║\n");
    printf("║                           -+-+- MACHINE  -+-+-                          ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════╝\n\n");

    printf("\t[1] Insert Elements\n");
    printf("\t[2] Display Hash Table\n");
    printf("\t[3] Search Element\n");
    printf("\t[4] Exit Program\n\n");
} 

int hash_function(){

}

int main(){
    // To set console output special characters
    SetConsoleOutputCP(CP_UTF8);

    // Variable setting
    char confirmation;
    int userchoice = 0;

    do{
        greet();
        printf("Enter your choice (1-4): ");
        if (scanf(" %d", &userchoice) != 1 || userchoice < 1 || userchoice > 5) {
            system("cls");
            printf("\t\t╔═════════════════════════════════════════╗\n");
            printf("\t\t║  Please enter a valid input (1-4 ONLY)  ║\n");
            printf("\t\t╚═════════════════════════════════════════╝\n");
            while (getchar() != '\n');
            userchoice = 0;
            continue;
        } 

        switch(userchoice){
            case 1:

            break;

            case 2:

            break;

            case 3:

            break;

            case 4:
                while(1) {
                    printf("\nDo you want to exit? (Y/N): ");
                    scanf(" %c", &confirmation);
                    while (getchar() != '\n');
                    
                    if (confirmation == 'y' || confirmation == 'Y') {	
                        printf("\t\t\t╔══════════════════════════╗\n");
                        printf("\t\t\t║  Exiting the program...  ║\n");
                        printf("\t\t\t╚══════════════════════════╝\n");
                        return 0;
                    }
                    else if (confirmation == 'n' || confirmation == 'N') {
                        system("cls");
                        printf("\t\t\t╔═════════════════════════════╗\n");
                        printf("\t\t\t║  Continuing the program...  ║\n");
                        printf("\t\t\t╚═════════════════════════════╝\n");
                        userchoice = 0;
                        break;
                    }
                    else {
                        system("cls");
                        printf("\t\t╔═════════════════════════════════════════╗\n");
                        printf("\t\t║  Please enter a valid input (1-4 ONLY)  ║\n");
                        printf("\t\t╚═════════════════════════════════════════╝\n");
                        continue;
                    }
                }
            break;
                
            default:

            break;
        }


    } while(userchoice != 4);


    return 0;
}