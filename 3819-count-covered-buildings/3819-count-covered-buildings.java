class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        int[] x_min = new int[n + 1];
        Arrays.fill(x_min, Integer.MAX_VALUE);
        
        int[] x_max = new int[n + 1];
        Arrays.fill(x_max, Integer.MIN_VALUE);
        
        int[] y_min = new int[n + 1];
        Arrays.fill(y_min, Integer.MAX_VALUE);
        
        int[] y_max = new int[n + 1];
        Arrays.fill(y_max, Integer.MIN_VALUE);

        for (int[] building : buildings) {
            int x = building[0], y = building[1];
            x_min[x] = Math.min(x_min[x], y);
            x_max[x] = Math.max(x_max[x], y);
            y_min[y] = Math.min(y_min[y], x);
            y_max[y] = Math.max(y_max[y], x);
        }

        int cnt = 0;
        for (int[] building : buildings) {
            int x = building[0];
            int y = building[1];
            if (y > x_min[x] && y < x_max[x] && x > y_min[y] && x < y_max[y])
                cnt++;
        }
        return cnt;
    }
}