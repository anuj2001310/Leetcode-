public class Solution {
    public int CountCoveredBuildings(int n, int[][] buildings) {
        var x_min = new int[n + 1];
        var x_max = new int[n + 1];
        var y_min = new int[n + 1];
        var y_max = new int[n + 1];
        
        for (int i = 0; i < n + 1; i++) {
            x_min[i] = Int32.MaxValue;
            y_min[i] = Int32.MaxValue;
        }
        
        for (int i = 0; i < n + 1; i++) {
            x_max[i] = Int32.MinValue;
            y_max[i] = Int32.MinValue;
        }
        
        foreach (var building in buildings) {
            int x = building[0], y = building[1];
            x_min[x] = Math.Min(x_min[x], y);
            x_max[x] = Math.Max(x_max[x], y);
            y_min[y] = Math.Min(y_min[y], x);
            y_max[y] = Math.Max(y_max[y], x);
        }

        int cnt = 0;
        foreach (var building in buildings) {
            int x = building[0];
            int y = building[1];
            if (y > x_min[x] && y < x_max[x] && x > y_min[y] && x < y_max[y])
                cnt++;
        }
        return cnt;
    }
}