nclude <stdio.h>
#include <string.h>

// Structure student declared
struct student {
    char name[20];
    int roll_no;
    char address[50];
    char branch[50];
};

int main() {
    // Create an array of student structures to store 1999 students
    struct student students[1999];

    // Initialize the data for each student
    for (int i = 0; i < 1999; i++) {
        snprintf(students[i].name, sizeof(students[i].name), "Student%d", i + 1);
        students[i].roll_no = i + 1;
        snprintf(students[i].address, sizeof(students[i].address), "Address%d", i + 1);
        snprintf(students[i].branch, sizeof(students[i].branch), "Branch%d", i + 1);
    }

    int searchRollNo;
    int continueSearching = 1;  // Initialize the variable for continuation

    while (continueSearching) {
        printf("Enter the roll number to search: ");
        if (scanf("%d", &searchRollNo) != 1) {
            printf("Invalid input. Please enter a valid roll number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;  // Continue the loop to prompt for a valid input
        }

        // Search for the student with the given roll number
        int found = 0;
        for (int i = 0; i < 1999; i++) {
            if (students[i].roll_no == searchRollNo) {
                printf("Student found:\n");
                printf("Name: %s\n", students[i].name);
                printf("Roll_No: %d\n", students[i].roll_no);
                printf("Address: %s\n", students[i].address);
                printf("Branch: %s\n", students[i].branch);
                found = 1;
                break; // Exit the loop once a match is found
            }
        }

        if (!found) {
            printf("Student with roll number %d not found.\n", searchRollNo);
        }

        printf("Do you want to continue searching? (1 for yes, 0 for no): ");
        int choice;
        if (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1)) {
            printf("Invalid choice. ");
        } else {
            continueSearching = (choice == 1);
        }

        // Clear input buffer
        while (getchar() != '\n');
    }

    return 0;
}

