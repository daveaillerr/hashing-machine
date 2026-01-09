#include <stdio.h>
#include <windows.h>

#define TABLE_SIZE 10

int hash_table[TABLE_SIZE];
int probing_count[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = -1;
        probing_count[i] = 0;
    }
}

int hash_function(int key) {
    return key % TABLE_SIZE;

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

}

int main(){
    // To set console output special characters
    SetConsoleOutputCP(CP_UTF8);
    initialize_table();

    // Variable setting
    char confirmation;
    int userchoice = 0;
    int key;

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
                printf("\n\tEnter number of keys: ");
                scanf("%d", &num_to_insert);
                system("cls");
                break;

            case 2:
                if (num_to_insert <= 0) {
                    printf("\n\tPlease use Option 1 first to set number of keys!\n");
                } else {
                    printf("\n\tEnter %d keys: ", num_to_insert);
                    for(int i = 0; i < num_to_insert; i++) {
                        scanf("%d", &key);
                        insert(key);
                    }
                    display();
                }
                system("pause");
                system("cls");
                break;

            case 3:
                printf("\n\tSearch: ");
                scanf("%d", &key);
                search(key);
                system("pause");
                system("cls");
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