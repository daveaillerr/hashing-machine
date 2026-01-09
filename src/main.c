#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

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
}

// Requirement: Linear Probing
void insert(int key) {
    int index = hash_function(key);
    int probes = 1;

    while (hash_table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        probes++;
        if (probes > TABLE_SIZE) return; // Table full
    }
    hash_table[index] = key;
    probing_count[index] = probes;
}

// Requirement: Search and report index
void search(int key) {
    int index = hash_function(key);
    int start = index;
    int found = 0;
    do {
        if (hash_table[index] == key) {
            printf("\nFound %d at index %d!\n", key, index);
            found = 1;
            break;
        }
        if (hash_table[index] == -1) break;
        index = (index + 1) % TABLE_SIZE;
    } while (index != start);
    
    if (!found) printf("\n%d not found.\n", key);
}

void error(){
    printf("\t\t\t╔══════════════════════════════════════╗\n");
    printf("\t\t\t║  Invalid input. Enter valid field!!  ║\n");
    printf("\t\t\t╚══════════════════════════════════════╝\n");
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
    char confirmation;
    int n = 0, key = 0, search_key;
    bool exit = true;

    while (1) {
        system("cls");
        initializeTable();
        greet();

        while(exit){
            // 1. INPUT PHASE 
            printf("Enter number of keys: ");
            if (scanf(" %d", &n) < 1 || n > 10) {
                while (getchar() != '\n'); 
                error();
                n = 0;
            }
            else {
                for (int i = 0; i < n; i++) {
                    printf("Enter keys: ");
                    if (scanf(" %d", &key) != 1){
                        while (getchar() != '\n'); 
                        error();
                        key = 0;
                        i--;
                    }
                    else{
                        insert(key);
                    }
                }
                while(1){
                    printf("Search: ");
                    if (scanf(" %d", &search_key) != 1){
                        while (getchar() != '\n'); 
                        error();
                        search_key = 0;
                    }
                    else{
                        exit = false;
                        break;
                    }
                }
            }
        }

        // 2. OUTPUT PHASE
        printf("\nHash Table: \t\t Number of probing\n");
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (hash_table[i] == -1) {
                printf("Index %d: %d\n", i, hash_table[i]);
            } else {
                // If probes > 1, it indicates a collision was resolved
                if (probing_count[i] > 1)
                    printf("Index %d: %-20d %d assuming only\n", i, hash_table[i], probing_count[i]);
                else
                    printf("Index %d: %-20d\n", i, hash_table[i]);
            }
        }

        search(search_key);

        // 3. EXIT OR PROCEED PHASE
        while (1) {
            printf("\nDo you want to try again? (Y/N): ");
            scanf(" %c", &confirmation);
            while (getchar() != '\n');

            if (confirmation == 'y' || confirmation == 'Y') {
                printf("\t\t\t╔═════════════════════════════╗\n");
                printf("\t\t\t║  Restarting the program...  ║\n");
                printf("\t\t\t╚═════════════════════════════╝\n");
                Sleep(1000);
            } 
            else if (confirmation == 'n' || confirmation == 'N') {
                system("cls");
                printf("\t\t\t╔══════════════════════════╗\n");
                printf("\t\t\t║  Exiting the program...  ║\n");
                printf("\t\t\t╚══════════════════════════╝\n");
                return 0;
                break; // Breaks the inner loop to restart the process
            } else {
                error();
            }
        }
    }

    return 0;
}