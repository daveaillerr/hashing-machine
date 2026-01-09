#include <stdio.h>
#include <windows.h>

#define TABLE_SIZE 10

int hash_table[TABLE_SIZE];
int probing_count[TABLE_SIZE];
int num_to_insert = 0; // Declared this globally so all cases can see it

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = -1;
        probing_count[i] = 0;
    }
}

int hash_function(int key) {
    return key % TABLE_SIZE;
} // Added missing brace

// Logic for Case 2: Linear Probing Insertion
void insert(int key) {
    int index = hash_function(key);
    int probes = 1;

    while (hash_table[index] != -1) {
        index = (index + 1) % TABLE_SIZE; // Move to next slot
        probes++;
        if (probes > TABLE_SIZE) {
            printf("\tTable is full!\n");
            return;
        }
    }
    hash_table[index] = key;
    probing_count[index] = probes;
}

// Logic for Case 2: Displaying the table
void display() {
    printf("\nHash Table: \t\t Number of probing\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == -1) {
            printf("Index %d: %-15d\n", i, hash_table[i]);
        } else {
            printf("Index %d: %-15d %d\n", i, hash_table[i], probing_count[i]);
        }
    }
}

// Logic for Case 3: Searching
void search(int key) {
    int index = hash_function(key);
    int start = index;
    do {
        if (hash_table[index] == key) {
            printf("\nFound %d at index %d!\n", key, index);
            return;
        }
        if (hash_table[index] == -1) break;
        index = (index + 1) % TABLE_SIZE;
    } while (index != start);
    printf("\n%d not found.\n", key);
}

void greet() {
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

int main() {
    SetConsoleOutputCP(CP_UTF8);
    initializeTable(); // Fixed naming to match declaration

    char confirmation;
    int userchoice = 0;
    int key;

    do {
        greet();
        printf("Enter your choice (1-4): ");
        if (scanf(" %d", &userchoice) != 1 || userchoice < 1 || userchoice > 4) {
            system("cls");
            printf("\t\t╔═════════════════════════════════════════╗\n");
            printf("\t\t║  Please enter a valid input (1-4 ONLY)  ║\n");
            printf("\t\t╚═════════════════════════════════════════╝\n");
            while (getchar() != '\n');
            userchoice = 0;
            continue;
        }

        switch(userchoice) {
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
                        userchoice = 0;
                        break;
                    }
                }
                break;
        }
    } while(userchoice != 4);

    return 0;
}