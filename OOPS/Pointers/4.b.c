#include <stdio.h>
#include <stdlib.h>

void getDims(int *rows, int *cols) {
    printf("Enter rows and cols: ");
    scanf("%d %d", rows, cols);
}

int** allocate2D_ArrayOfPointers(int rows, int cols) {
    int **arr = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        arr[i] = (int*) malloc(cols * sizeof(int));
    return arr;
}

void accept2D(int **arr, int rows, int cols) {
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &arr[i][j]);
}

void print2D(int **arr, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int main() {
    int rows, cols;
    getDims(&rows, &cols);
    int **arr = allocate2D_ArrayOfPointers(rows, cols);
    accept2D(arr, rows, cols);
    print2D(arr, rows, cols);

    for (int i = 0; i < rows; i++) free(arr[i]);
    free(arr);
    return 0;
}
