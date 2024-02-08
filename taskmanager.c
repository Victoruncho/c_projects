
#include <stdio.h>
#include "processes.h"

void print_processes() {
    printf("List of processes:\n");
    for (int i = 0; i < processescount; ++i) {
        printf("ID: %d, Name: %s\n", processes[i].id, processes[i].name);
    }
}

int main() {
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Create new process\n");
        printf("2. Display all processes\n");
        printf("3. Stop a process\n");
        printf("0. Exit\n");
        printf("Make your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char name[30];
                    printf("Enter process name: ");
                    scanf("%s", name);
                    int id = createnewprocess(name);
                    if (id != 0) {
                        printf("Process created successfully. ID: %d\n", id);
                    } else {
                        printf("Maximum number of processes reached. Cannot create new process.\n");
                    }
                }
                break;
            case 2:
                print_processes();
                break;
            case 3:
                {
                    int processid;
                    printf("Enter process ID to stop: ");
                    scanf("%d", &processid);
                    stopprocess(processid);
                    printf("Process stopped.\n");
                }
                break;
            case 0:
                printf("Exiting task manager.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
