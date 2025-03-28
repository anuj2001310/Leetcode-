class Solution {
    static class pair {
        int val;
        int row;
        int col;

        pair(int val, int row, int col) {
            this.val = val;
            this.row = row;
            this.col = col;
        }
    }

    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public int[] maxPoints(int[][] grid, int[] queries) {
        int k = queries.length;
        var ans = new int[k];

        int n = grid.length, m = grid[0].length;
        var vis = new boolean[n][m];

        PriorityQueue<pair> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        ArrayList<int[]> arr = new ArrayList<>();

        for (int i = 0; i < k; ++i)
            arr.add(new int[] { queries[i], i });

        Collections.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));

        pq.offer(new pair(grid[0][0], 0, 0));
        vis[0][0] = true;
        int cnt = 0;

        for (int i = 0; i < k; ++i) {
            int thresh = arr.get(i)[0];
            int idx = arr.get(i)[1];

            while (!pq.isEmpty() && pq.peek().val < thresh) {
                pair top = pq.poll();

                ++cnt;
                int val = top.val;
                int r = top.row;
                int c = top.col;

                for (int[] dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                            !vis[nr][nc]) {
                        vis[nr][nc] = true;
                        pq.offer(new pair(grid[nr][nc], nr, nc));
                    }
                }
            }
            ans[idx] = cnt;
        }
        return ans;
    }
}