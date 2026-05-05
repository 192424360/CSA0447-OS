#include <stdio.h>
#include <string.h>

#define MAX 50

char files[MAX][50];
int count = 0;

void createFile() {
    printf("Enter file name: ");
    scanf("%s", files[count]);
    count++;
    printf("File created successfully.\n");
}

void deleteFile() {
    char name[50];
    printf("Enter file name to delete: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(files[i], name) == 0) {
            for(int j = i; j < count-1; j++) {
                strcpy(files[j], files[j+1]);
            }
            count--;
            printf("File deleted.\n");
            return;
        }
    }
    printf("File not found.\n");
}

void searchFile() {
    char name[50];
    printf("Enter file name to search: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(files[i], name) == 0) {
            printf("File found.\n");
            return;
        }
    }
    printf("File not found.\n");
}

void displayFiles() {
    printf("\nFiles in Directory:\n");
    for(int i = 0; i < count; i++) {
        printf("%s\n", files[i]);
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n1.Create File\n2.Delete File\n3.Search File\n4.Display Files\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createFile(); break;
            case 2: deleteFile(); break;
            case 3: searchFile(); break;
            case 4: displayFiles(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}