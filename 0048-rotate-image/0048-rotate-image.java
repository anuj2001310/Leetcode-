class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        // Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        // Now reverse each row
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = t;
            }
        }
    }
}