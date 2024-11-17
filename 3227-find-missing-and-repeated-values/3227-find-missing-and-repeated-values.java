class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int[] result = new int[2];
        int row = grid.length;
        int col = grid[0].length;
        int square = row * col;
        int[] arr = new int[square + 1];
        for (int i = 0; i <= square; i++)
            arr[i] = -1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[grid[i][j]]++;
            }
        }
        for (int i = 1; i <= square; i++) {
            if (arr[i] == 1) {
                result[0] = (i);
                break;
            }
        }
        for (int i = 1; i <= square; i++) {
            if (arr[i] == -1) {
                result[1] = (i);
                break;
            }
        }
        return result;
    }
}