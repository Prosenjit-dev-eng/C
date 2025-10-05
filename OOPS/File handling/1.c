#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.dat"

typedef struct {
    int roll;
    char name[50];
    int marks[5];
    int deleted;  // 0 = valid, 1 = logically deleted
} Student;

// Function Prototypes
void addRecord();
void displayRecords();
void searchRecord();
void editRecord();
void logicalDelete();
void physicalDelete();

int rollExists(int roll);

int main() {
    int choice;
    while (1) {
        printf("\n=== Student Record Management ===\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by Roll\n");
        printf("4. Edit Record\n");
        printf("5. Delete Record (Logical)\n");
        printf("6. Delete Record (Physical)\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: editRecord(); break;
            case 5: logicalDelete(); break;
            case 6: physicalDelete(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Check if roll number exists already
int rollExists(int roll) {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return 0;

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll == roll && s.deleted == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Add a new student record
void addRecord() {
    FILE *fp = fopen(FILENAME, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    if (rollExists(s.roll)) {
        printf("Roll number already exists!\n");
        fclose(fp);
        return;
    }

    printf("Enter Name: ");
    getchar(); // to clear newline
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';  // remove newline

    printf("Enter 5 subject marks:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s.marks[i]);
    }
    s.deleted = 0;

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Record added successfully.\n");
}

// Display all student records
void displayRecords() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    Student s;
    printf("\n%-10s %-20s %-10s\n", "Roll", "Name", "Total Score");
    printf("--------------------------------------------\n");

    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.deleted == 0) {
            int total = 0;
            for (int i = 0; i < 5; i++) total += s.marks[i];
            printf("%-10d %-20s %-10d\n", s.roll, s.name, total);
        }
    }
    fclose(fp);
}

// Search record by roll number
void searchRecord() {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll == roll && s.deleted == 0) {
            printf("Roll: %d\nName: %s\nMarks: ", s.roll, s.name);
            for (int i = 0; i < 5; i++) printf("%d ", s.marks[i]);
            printf("\n");
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Record not found!\n");
}

// Edit a record
void editRecord() {
    int roll;
    printf("Enter roll number to edit: ");
    scanf("%d", &roll);

    FILE *fp = fopen(FILENAME, "rb+");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll == roll && s.deleted == 0) {
            printf("Editing record for %s\n", s.name);

            printf("Enter new name: ");
            getchar();
            fgets(s.name, 50, stdin);
            s.name[strcspn(s.name, "\n")] = '\0';

            printf("Enter new 5 subject marks:\n");
            for (int i = 0; i < 5; i++) {
                printf("Subject %d: ", i + 1);
                scanf("%d", &s.marks[i]);
            }

            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            printf("Record updated successfully.\n");
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Record not found!\n");
}

// Logical Delete
void logicalDelete() {
    int roll;
    printf("Enter roll number to delete (logical): ");
    scanf("%d", &roll);

    FILE *fp = fopen(FILENAME, "rb+");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll == roll && s.deleted == 0) {
            s.deleted = 1;
            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            printf("Record logically deleted.\n");
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Record not found!\n");
}

// Physical Delete (rewrite file without deleted records)
void physicalDelete() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Error creating temp file!\n");
        fclose(fp);
        return;
    }

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.deleted == 0) {
            fwrite(&s, sizeof(Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    remove(FILENAME);
    rename("temp.dat", FILENAME);

    printf("Physical deletion completed. Deleted records removed permanently.\n");
}
