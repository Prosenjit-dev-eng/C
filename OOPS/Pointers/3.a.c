#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r,c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    int *arr[r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(c * sizeof(int));
    }
    printf("Enter elements of the 2D array:\n");
    for (int i = 0; i < r; i++)
    {   
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }   
    }
    printf("Elements of the 2D array:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < r; i++)
    {
        free(arr[i]);
    }    
    return 0;
}