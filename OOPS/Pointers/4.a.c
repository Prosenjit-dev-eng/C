// 4. Implement the programs in Q.2 and 3 breaking it into functions for i) getting the dimensions from user,
// ii) dynamic memory allocation, iii) accepting the values and iv) printing the values.
// Q.2
#include <stdio.h>
#include<stdlib.h>
int getDimension(){
    int n;
    printf("Enter dimension: ");
    scanf("%d",&n);
    return n;
}
int *allocate1D(int n){
    return (int*)malloc(n*sizeof(int));
}
void accept1D(int *arr, int n){
    printf("Give the elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",arr+i);
    }
    
}
void print1D(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    
}
int main()
{
    int n = getDimension();
    int *arr = allocate1D(n);
    accept1D(arr,n);
    print1D(arr,n);
    return 0;
}