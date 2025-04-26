#include <stdio.h>

// Função: swapRows
// Objetivo: Trocar as linhas 'row1' e 'row2' da matriz.
// Para cada coluna, realiza a troca dos elementos entre as linhas especificadas.
void swapRows(int size, int matrix[size][size], int row1, int row2) {
    for (int col = 0; col < size; col++) {
        int temp = matrix[row1][col];
        matrix[row1][col] = matrix[row2][col];
        matrix[row2][col] = temp;
    }
}

// Função: printMatrix
// Objetivo: Imprimir a matriz no console.
// Percorre cada linha e coluna, exibindo os elementos.
void printMatrix(int size, int matrix[size][size]) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

int main() {
    // Define o tamanho da matriz e a própria matriz.
    int size = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Exibe a matriz original.
    printf("Matriz original:\n");
    printMatrix(size, matrix);

    // Define quais linhas serão trocadas e realiza a troca.
    int row1 = 0, row2 = 2;
    swapRows(size, matrix, row1, row2);

    // Exibe a matriz após a troca de linhas.
    printf("\nMatriz com as linhas %d e %d trocadas:\n", row1, row2);
    printMatrix(size, matrix);

    return 0;
}
