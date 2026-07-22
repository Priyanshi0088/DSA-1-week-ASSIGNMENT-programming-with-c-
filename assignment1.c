#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 100
void displayMarks(const int marks[], int n);
int calculateTotal(const int marks[], int n);
float calculateaverage(int total, int n);
int findHighest(const int marks[], int n);
int findlowest(const int marks[], int n);
int searchStudent(const int marks[], int n, int targetvalue);
void sortMarksAscending(int marks[], int n);
int main() {                                                                                 
       int marks[MAX_STUDENTS];
       int n = 0;
    int choice;
    int target, searchIndex;
    int sorted = 0; 
    printf("========================================= \n");
    printf(" STUDENT MARKS ANALYZER SYSTEM \n");
    printf("=========================================\n");
    while (1) {
        printf("Enter the number of students (1 to %d): ", MAX_STUDENTS);
        if (scanf("%d", &n) == 1 && n >= 1 && n <= MAX_STUDENTS) {
            break;
        }
        printf("Invalid input. Please enter a valid number within the range.\n");
        while (getchar() != '\n'); 
    }
    printf("\nEnter marks for %d students:\n", n);
    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Student %d Marks (0 - 100): ", i + 1);
            if (scanf("%d", &marks[i]) == 1 && marks[i] >= 0 && marks[i] <= 100) {
                break;
            }
            printf("Invalid marks. Please enter an integer between 0 and 100.\n");
            while (getchar() != '\n'); 
        }
    }

    
    do {
        printf("\n=========================================\n");
        printf(" OPTIONS \n");
        printf("=========================================\n");
        printf("1. Display Marks\n");
        printf("2. Calculate Total & Average\n");
        printf("3. Find Highest & Lowest Marks\n");
        printf("4. Search for a Student's Marks\n");
        printf("5. Sort Marks in Ascending Order\n");
        printf("6. Exit\n");
        printf("=========================================\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            while (getchar() != '\n');
            continue;
        }

switch (choice) {
        case 1: 
            displayMarks(marks, n);
            break;

        case 2: {
           
            int total = calculateTotal(marks, n); 
            float average = calculateaverage(total, n); 
            printf("\n--- Statistics ---\n");
            printf("Total Marks: %d\n", total);
            printf("Average Marks: %.2f\n", average);
            break;
        }

        case 3:
            printf("\n--- Extremes ---\n");
            printf("Highest Mark: %d\n", findHighest(marks, n));
            printf("Lowest Mark:  %d\n", findlowest(marks, n));
            break;

            case 4:
                printf("\nEnter the marks value to search for: ");
                if (scanf("%d", &target) != 1) {
                    printf("Invalid search term.\n");
                    while (getchar() != '\n');
                    break;
                }
                
                searchIndex = searchStudent(marks, n, target);
                if (searchIndex!= -1) {
                    printf("Match found! Student %d has the marks %d.\n", searchIndex + 1, target);
                } else {
                    printf("Marks value %d not found in the records.\n", target);
                }
                break;

            case 5:
                sortMarksAscending(marks, n);
                sorted = 1;
                printf("\nMarks sorted successfully in ascending order.\n");
                displayMarks(marks, n);
                break;

            case 6:
                printf("\nExiting the system. Thank you!\n");
                break;

            default:
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice!= 6);

    return 0;
}


void displayMarks(const int marks[], int n) {
    printf("\n--- Current Student Marks List ---\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: %d\n", i + 1, marks[i]);
    }
}


int calculateTotal(const int marks[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += marks[i];
    }
    return total;
}

float calculateaverage(int total, int n) {
    return (float)total /n;
}


int findHighest(const int marks[], int n) {
    int max = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] > max) {
            max = marks[i];
        }
    }
    return max;
}

int findlowest(const int marks[], int n) {
    int min = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] < min) {
            min = marks[i];
        }
    }
    return min;
}

int searchStudent(const int marks[], int n, int targetvalue) {
    for (int i = 0; i < n; i++) {
        if (marks[i] == targetvalue) {
            return i; 
        }
    }
    return -1; 
}
void sortMarksAscending(int marks[], int n) {
    int temp;
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] > marks[j + 1]) {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break; 
        }
    }
}