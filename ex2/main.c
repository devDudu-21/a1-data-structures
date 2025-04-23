#include <stdio.h>

void swapRows(int size, int matrix[size][size], int row1, int row2) {
    for (int col = 0; col < size; col++) {
        int temp = matrix[row1][col];
        matrix[row1][col] = matrix[row2][col];
        matrix[row2][col] = temp;
    }
}

void printMatrix(int size, int matrix[size][size]) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int size = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matriz original:\n");
    printMatrix(size, matrix);

    int row1 = 0, row2 = 2;
    swapRows(size, matrix, row1, row2);

    printf("\nMatriz com as linhas %d e %d trocadas:\n", row1, row2);
    printMatrix(size, matrix);

    return 0;
}
