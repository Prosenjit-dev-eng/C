// 3. Implement a two dimensional array of integers using a) array of pointers b) pointer to pointer (with two
// malloc statements and again with one malloc statement, c) pointer to an array. Accept the value for the
// elements and print those.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int **p = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        p[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("Enter elements of the 2D array:\n");
    for (int i = 0; i < rows; i++)
    { 
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &p[i][j]);
        }   
    }
    printf("Elements of the 2D array:\n");
    for (int i = 0; i < rows; i++)
    {      
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++)
    {
        free(p[i]);
    }
    return 0;
}