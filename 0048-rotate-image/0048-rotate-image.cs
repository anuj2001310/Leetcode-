public class Solution {
    public void Rotate(int[][] matrix) {
        for(var i = 0; i < matrix.Length; i++) {
            for(var j = 0; j < i; j++) {
                var a = matrix[i][j];
                var b = matrix[j][i];
                matrix[i][j] = b;
                matrix[j][i] = a;
            }
        }

        for(var i = 0; i < matrix.Length; i++) {
            var r = matrix[i];
            matrix[i] = r.Reverse().ToArray();
        }
    }
}