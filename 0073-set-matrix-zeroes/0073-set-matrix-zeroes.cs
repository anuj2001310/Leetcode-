public class Solution {
    public void SetZeroes(int[][] matrix) {
        var n = matrix.Length;
        var m = matrix[0].Length;

        bool[] row = new bool[n];
        bool[] col = new bool[m];
        for (var i = 0; i < n; i++) {
            for (var j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
}