#include <stdio.h>
#include <stdlib.h>
// one malloc statement
int main()
{
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **arr = (int**)malloc(rows * sizeof(int *)+rows * cols * sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)(arr+rows)+i*cols;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", (*(arr + i) + j));
        }
    }
        for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    
    return 0;
}