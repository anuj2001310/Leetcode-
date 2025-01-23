public class Solution {
    public int CountServers(int[][] grid) {
        var n = grid.Length;
        var m = grid[0].Length;
        int communicableServersCount = 0;
        var rowCounts = new int[m];
        var lastServerInCol = new int[n];
        for (int i = 0; i < n; i++)
            lastServerInCol[i] = -1;
        

        for (int row = 0; row < n; row++) {
            int serverCountInRow = 0;
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    serverCountInRow++;
                    rowCounts[col]++;
                    lastServerInCol[row] = col;
                }
            }

            if (serverCountInRow != 1) {
                communicableServersCount += serverCountInRow;
                lastServerInCol[row] = -1;
            }
        }

        for (int row = 0; row < n; row++) {
            if (lastServerInCol[row] != -1 && rowCounts[lastServerInCol[row]] > 1)
                communicableServersCount++;
        }

        return communicableServersCount;
    }
}