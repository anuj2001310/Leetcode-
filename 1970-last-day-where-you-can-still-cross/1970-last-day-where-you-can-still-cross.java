class Solution {

    private int[][] dest = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    private int row, cols;

    public int latestDayToCross(int row, int cols, int[][] cells) {

        this.row = row;
        this.cols = cols;

        int left = 1, right = cells.length, ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canCross(mid, cells)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;

    }

    private boolean canCross(int day, int[][] cells) {
        int[][] grid = new int[row][cols];

        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[row][cols];

        for (int c = 0; c < cols; c++) {
            if (grid[0][c] == 0) {
                queue.offer(new int[] { 0, c });
                visited[0][c] = true;
            }
        }

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int r = curr[0], c = curr[1];

            if (r == row - 1)
                return true;

            for (int[] dir : dest) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < row && nc >= 0 && nc < cols && !visited[nr][nc] && grid[nr][nc] == 0) {
                    visited[nr][nc] = true;
                    queue.offer(new int[] { nr, nc });
                }
            }
        }

        return false;
    }
}