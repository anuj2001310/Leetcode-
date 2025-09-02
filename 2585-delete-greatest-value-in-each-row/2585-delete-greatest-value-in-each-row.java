class Solution {
    public int deleteGreatestValue(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        PriorityQueue<Integer> pq [] = new PriorityQueue[n];
        for (int i = 0; i < n; ++i) {
            PriorityQueue<Integer> t = new PriorityQueue<>((a, b) -> b - a);
            for (int val : grid[i])
                t.offer(val);
            pq[i] = t;
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int num = 0;
            for (int j = 0; j < n; ++j) {
                int ele = pq[j].poll();
                num = Math.max(num, ele);
            }
            ans += num;
        }
        return ans;
    }
}