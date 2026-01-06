class Solution {
    public int findChampion(int[][] grid) {
        int n = grid.length;
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            int t = 0;
            for (int g : grid[i])
                if (g == 1)
                    t++;
            
            if (t > cnt) {
                cnt = t;
                ans = i;
            }
        }
        return ans;
    }
}