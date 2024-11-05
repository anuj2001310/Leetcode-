void swap(int* x, int* y) {
    int tem = *x;
    *x = *y;
    *y = tem;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = i; j < (*matrixColSize); ++j)
            swap(&matrix[i][j], &matrix[j][i]);
    }

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize / 2; ++j)
            swap(&matrix[i][j], &matrix[i][matrixSize - j - 1]);
    }
}