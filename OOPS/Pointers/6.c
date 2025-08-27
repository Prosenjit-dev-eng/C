#include <stdio.h>
#include<stdlib.h>
typedef struct Persons
{
   int *age;
   char **name;
}Persons;
// ✅ Instead, you should allocate one Persons struct, and inside it allocate arrays for name and age:
void allocate(Persons **p, int n){
    // See call by reference and call by values part
    *p = malloc(n*sizeof(Persons));
    (*p)->name = (char**)malloc(n*sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        (*p)->name[i] = malloc(16*sizeof(char));
    }
    (*p)->age = (int*)malloc(n*sizeof(int));
}
// You don’t need double pointer unless you’re reallocating the whole array inside the sort (which you’re not).
void sort(Persons *p, int n){
    for (int i = 0; i < n-1; i++)
    {
        int idx = 0;
        for (int j = i; j < n - i -1 ; j++)
        {
            // swap age
            if (p->age[j]>p->age[j+1])
            {
                idx = 1;
                int temp = p->age[j];
                p->age[j] = p->age[j+1];
                p->age[j+1] = temp;
            // swap names
                char *t = p->name[j];
                p->name[j] = p->name[j+1];
                p->name[j+1] = t;
 
            }
            if(idx == 0) break;
            
        }
        
    }
    
}
void print(Persons*p,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%s - %d \n",p->name[i],p->age[i]);
    }
    
}
int main()
{
    int no_of_persons;
    printf("Enter no of persons: ");
    scanf("%d", &no_of_persons);

    Persons *p;
    allocate(&p,no_of_persons);
    printf("Enter name & age: \n");
    for (int i = 0; i < no_of_persons; i++)
    {
        scanf("%s %d",p->name[i],&p->age[i]);
    }
    print(p,no_of_persons);
    sort(p,no_of_persons);
    printf("After sorting:\n");
    print(p,no_of_persons);
    return 0;
}