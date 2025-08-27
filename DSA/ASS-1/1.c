// 1.      
// Write a program which will accept some integer
// data from the user input (or from a file) and store the data in an array. The
// array will end with the value ‘0’.

#include <stdio.h>
#define max_size 100
int main()
{
    int input;
    int arr[max_size];
    int pos = 0;
    printf("Enter the array: \n");
    while (1)
    {
       scanf("%d",&input); 
       if(input == 0) break;
       if(pos < max_size){
       arr[pos] = input;
       pos++;
       }
    }
    for (int i = 0; i < pos; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}