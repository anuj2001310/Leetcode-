class Solution {
    public int numberOfSubmatrices(char[][] grid) {

        int[][] prev = new int[grid[0].length][2];
        int n = grid.length;
        int m = grid[0].length;
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            int curX = 0;
            int curY = 0;

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 'X') {
                    prev[j][0]++;
                } else if (grid[i][j] == 'Y') {
                    prev[j][1]++;
                }

                curX += prev[j][0];
                curY += prev[j][1];

                if (curX > 0 && curX == curY) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
}