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
int compareByRollAsc(Student a,Student b){
 return a.roll>b.roll;
}
int compareByRollDsc(Student a,Student b){
 return a.roll<b.roll;
}
int compareByScoreAsc(Student a,Student b){
 return a.score>b.score;
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

int main()
{
    Student arr[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%s %d %f",arr[i].name,&arr[i].roll,&arr[i].score);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("The structure are : %s %d %.2f\n",arr[i].name,arr[i].roll,arr[i].score);
    }
    sort(arr,3,compareByRollAsc);
    for (int i = 0; i < 3; i++)
    {
        printf("The structure are after sorting : %s %d %.2f\n",arr[i].name,arr[i].roll,arr[i].score);
    }
    return 0;
}