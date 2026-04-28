class Solution {
    public int minOperations(int[][] grid, int x) {
        int m = grid.length;
        int n = grid[0].length;
        int arr[] = new int[m * n];
        int k = 0;
        int rem = grid[0][0] % x;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[k++] = grid[i][j];
                if (grid[i][j] % x != rem)
                    return -1;
            }
        }

        Arrays.sort(arr);
        int num = arr[arr.length / 2];
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            count += Math.abs(num - arr[i]) / x;
        }
        return count;

    }
}