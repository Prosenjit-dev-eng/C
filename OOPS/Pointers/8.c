#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// 8. Consider an array that stores roll, name, and score of number of students. Develop a function to sort the array. User of sort() will develop the comparison function for sorting on roll/score and ascending or descending order and reuse the same sort() function.

typedef struct Student
{
    int roll;
    char name[31];
    float score;
}Student;
// scending order by roll
int compareByRollAsc(Student a,Student b){
 return a.roll>b.roll;
}
// Descending order by roll
int compareByRollDsc(Student a,Student b){
 return a.roll<b.roll;
}
// Ascending order by score
int compareByScoreAsc(Student a,Student b){
 return a.score>b.score;
}
// Descending order by score
int compareByScoreDsc(Student a,Student b){
 return a.score<b.score;
}
void sort(Student arr[], int n,int (*cmp)(Student,Student)){
    for (int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n-i-1; j++)
        {
            if(cmp(arr[j],arr[j+1])){
                flag = 1;
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
        if(!flag) break;
        
    }
    
}
// print students
void printStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d %.2f\n", arr[i].name, arr[i].roll, arr[i].score);
    }
}
int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student arr[n];
    printf("Enter name roll score:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d %f", arr[i].name, &arr[i].roll, &arr[i].score);
    }

    int choice;
    printf("\nSort by:\n");
    printf("1. Roll Ascending\n");
    printf("2. Roll Descending\n");
    printf("3. Score Ascending\n");
    printf("4. Score Descending\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: sort(arr, n, compareByRollAsc); break;
        case 2: sort(arr, n, compareByRollDsc); break;
        case 3: sort(arr, n, compareByScoreAsc); break;
        case 4: sort(arr, n, compareByScoreDsc); break;
        default: 
            printf("Invalid choice!\n");
            break;
    }

    printf("\nSorted students:\n");
    printStudents(arr, n);
    return 0;
}