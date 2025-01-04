void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    int m = (*matrixColSize);

    bool* row = (bool*)calloc(sizeof(bool), n);
    bool* col = (bool*)calloc(sizeof(bool), m);
    for (uint i = 0; i < n; ++i) {
        for (uint j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (uint i = 0; i < n; i++) {
        for (uint j = 0; j < m; j++) {
            if (row[i] || col[j])
                matrix[i][j] = 0;
        }
    }
}