#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
struct Student {
    int id;
    char name[50];
    float marks;
    struct Student *next;
};

struct Student *head = NULL;

// Add Student
void addStudent() {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Student *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Student Added Successfully!\n");
}

// Display Students
void displayStudents() {
    struct Student *temp = head;

    if (temp == NULL) {
        printf("No Records Found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (temp != NULL) {
        printf("ID: %d\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("Marks: %.2f\n", temp->marks);
        printf("----------------------\n");
        temp = temp->next;
    }
}

// Search Student
void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    struct Student *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Student Found!\n");
            printf("ID: %d\nName: %s\nMarks: %.2f\n", temp->id, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student Not Found!\n");
}

// Delete Student
void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    struct Student *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Student Deleted!\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student Not Found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student Deleted!\n");
}

// Update Student
void updateStudent() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    struct Student *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", temp->name);

            printf("Enter New Marks: ");
            scanf("%f", &temp->marks);

            printf("Record Updated!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Student Not Found!\n");
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }

    return 0;
}
