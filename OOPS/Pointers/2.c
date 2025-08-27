// 2. Implement a one dimensional array of integers where array size of the array will be provided during
// runtime. Accept the value for the elements and print those using pointers.
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    

    for (int i = 0; i < n; i++)
    {
        printf("Element at index %d: %d\n", i, *(arr + i));
    }
    
    return 0;
}