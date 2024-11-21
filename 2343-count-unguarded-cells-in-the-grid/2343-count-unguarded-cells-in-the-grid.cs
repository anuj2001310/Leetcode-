public class Solution {
    public int CountUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[, ]vis = new int[m, n];

        foreach (int[] arr in guards)
            vis[arr[0], arr[1]] = 2;
        
        foreach (int[] arr in walls)
            vis[arr[0], arr[1]] = 3;
        
        for (int i = 0; i < guards.Length; ++i) {
            int r = guards[i][0];
            int c = guards[i][1];

            int left = c - 1, right = c + 1;
            int up = r - 1, down = r + 1;
            
            //Left-Movement
            while (left >= 0) {
                if (vis[r, left] == 3 || vis[r, left] == 2)
                    break;
                vis[r, left] = 1;
                left--;  
            }

            //Right-Movement
            while (right < n) {
                if (vis[r, right] == 3 || vis[r, right] == 2)
                    break;
                vis[r, right] = 1;
                right++;
            }

            //Up-Movement
            while (up >= 0) {
                if (vis[up, c] == 3 || vis[up, c] == 2)
                    break;
                vis[up, c] = 1;
                up--;
            }

            //Down-Movement
            while (down < m) {
                if (vis[down, c] == 3 || vis[down, c] == 2)
                    break;
                vis[down, c] = 1;
                down++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                if (vis[i, j] == 0)
                    cnt++;
        
        return cnt;
    }
}