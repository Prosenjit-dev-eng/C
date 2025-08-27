// 5. Store name and age of number of persons (number provided at run time). Collect the data and display
// data in the ascending order of age. Implement without using structure. Write functions for memory
// allocation of the list, sorting and display of data.
#include <stdio.h>
#include <stdlib.h>
void allocate(char ***names, int **age, int n){
    // See call by reference and call by values part
    *names = (char**)malloc(n*sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        (*names)[i] = (char*)malloc(16*sizeof(char*));
    }
    *age = (int*)malloc(n*sizeof(int));
}

void sort(char **names, int *age, int n){
    for (int i = 0; i < n-1; i++)
    {
        int idx = 0;
        for (int j = i; j < n - i -1 ; j++)
        {
            // swap age
            if (age[j]>age[j+1])
            {
                idx = 1;
                int temp = age[j];
                age[j] = age[j+1];
                age[j+1] = temp;
            // swap names
                char *t = names[j];
                names[j] = names[j+1];
                names[j+1] = t;
 
            }
            if(idx == 0) break;
            
        }
        
    }
    
}
void print(char **names,int *age, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%s - %d \n",names[i],age[i]);
    }
    
}
int main()
{
    int no_of_persons;
    printf("Enter no of persons: ");
    scanf("%d", &no_of_persons);

    char **names;
    int *age;
    printf("Enter name & age: \n");
    allocate(&names,&age,no_of_persons);
    for (int i = 0; i < no_of_persons; i++)
    {
        scanf("%s %d",names[i],&age[i]);
    }
    sort(names,age,no_of_persons);
    print(names,age,no_of_persons);

    return 0;
}