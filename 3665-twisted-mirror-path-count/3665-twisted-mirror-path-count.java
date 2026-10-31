class Solution {
    int[][] dirs = new int[][] { { 0, 1, 1 }, { 1, 0, 2 } }; // index 0 is right, 1 is down
    long MOD = 1_000_000_007L;
    Long[][] dp;

    public int uniquePaths(int[][] grid) {
        int len = grid.length;
        int bre = grid[0].length;
        dp = new Long[len][bre];

        long res = dfs(0, 0, grid);
        return (int) res;
    }

    private long dfs(int x, int y, int[][] grid) {
        int len = grid.length;
        int bre = grid[0].length;
        if (x == len - 1 && y == bre - 1) {
            return 1L;
        }
        if (!isValid(x, y, grid)) {
            return -1;
        }
        if (dp[x][y] != null) {
            return dp[x][y];
        }
        long count = 0L;
        if (grid[x][y] == 1) {
            return -1; // should not happen
        }
        for (int[] dir : dirs) {
            int[] arr = fixMirror(x + dir[0], y + dir[1], dir[2], grid);
            if (isValid(arr[0], arr[1], grid)) {
                count += dfs(arr[0], arr[1], grid);
            }
        }

        return dp[x][y] = count % MOD;
    }

    private int[] fixMirror(int x, int y, int dir, int[][] grid) {
        if (isValid(x, y, grid)) {
            if (grid[x][y] == 0)
                return new int[] { x, y };
            if (dir == 1)
                return fixMirror(x + 1, y, 2, grid);
            else 
                return fixMirror(x, y + 1, 1, grid);
        }
        return new int[] { -1, -1 };
    }

    private boolean isValid(int x, int y, int[][] grid) {
        int len = grid.length;
        int bre = grid[0].length;
        if (x >= 0 && x < len && y >= 0 && y < bre) {
            return true;
        }
        return false;
    }
}