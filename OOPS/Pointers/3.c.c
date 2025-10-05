#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int (*p)[rows];
    p = malloc(cols*sizeof(*p));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)  
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    free(p);
    return 0;
}