#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define TABLE_SIZE 10

int hash_table[TABLE_SIZE];
int probing_count[TABLE_SIZE];

void initializeTable() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = -1;
        probing_count[i] = 0;
    }
}

int hash_function(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash_function(key);
    int probes = 1;

    while (hash_table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        probes++;
        if (probes > TABLE_SIZE) return;
    }
    hash_table[index] = key;
    probing_count[index] = probes;
}

void search(int key) {
    int index = hash_function(key);
    int start = index;
    int found = 0;

    do {
        if (hash_table[index] == key) {
            printf("\t\t╔═════════════════════════════╗\n");
            printf("\t\t      Found %d at index %d!\n", key, index);
            printf("\t\t╚═════════════════════════════╝\n");
            found = 1;
            break;
        }
        if (hash_table[index] == -1) break;
        index = (index + 1) % TABLE_SIZE;
    } while (index != start);

    if (!found) {
        printf("\t\t╔═════════════════════════════╗\n");
        printf("\t\t       %d not found!\n", key);
        printf("\t\t╚═════════════════════════════╝\n");
    }
}

void error() {
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
    int n, key, search_key;
    bool exit;

label:
    exit = true;
    n = key = search_key = 0;

    system("cls");
    initializeTable();
    greet();

    while (exit) {
        printf("Enter number of keys: ");
        if (scanf("%d", &n) != 1 || n > 10) {
            while (getchar() != '\n');
            error();
        } else {
            int i;
            printf("\n");
            for (i = 0; i < n; i++) {
                printf("Enter keys: ");
                if (scanf("%d", &key) != 1) {
                    while (getchar() != '\n');
                    error();
                    i--;
                } else {
                    insert(key);
                }
            }

            while (1) {
                printf("\nSearch: ");
                if (scanf("%d", &search_key) != 1) {
                    while (getchar() != '\n');
                    error();
                } else {
                    exit = false;
                    break;
                }
            }
        }
    }

    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║ Hash Table:  \t\t      Number of probing              ║\n");
    printf("╠════════════════════════════════════════════════════════════╣");

    {
        int i;
        for (i = 0; i < TABLE_SIZE; i++) {
            if (hash_table[i] == -1)
                printf("\n║ Index %d: %-50d║", i, hash_table[i]);
            else if (probing_count[i] > 1)
                printf("\n║ Index %d: %-20d %d assuming only\t\t     ║",
                       i, hash_table[i], probing_count[i]);
            else
                printf("\n║ Index %d: %-50d║", i, hash_table[i]);
        }
    }

    printf("\n╚════════════════════════════════════════════════════════════╝\n\n");

    search(search_key);

    while (1) {
        printf("\nDo you want to try again? (Y/N): ");
        scanf(" %c", &confirmation);
        while (getchar() != '\n');

        if (confirmation == 'Y' || confirmation == 'y') {
            printf("\t\t\t╔═════════════════════════════╗\n");
            printf("\t\t\t║  Restarting the program...  ║\n");
            printf("\t\t\t╚═════════════════════════════╝\n");
            Sleep(1000);
            goto label;
        } else if (confirmation == 'N' || confirmation == 'n') {
            printf("\t\t\t╔══════════════════════════╗\n");
            printf("\t\t\t║  Exiting the program...  ║\n");
            printf("\t\t\t╚══════════════════════════╝\n");
            return 0;
        } else {
            error();
        }
    }
}