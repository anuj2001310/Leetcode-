class Solution {
    public int minimumIndex(int[] capacity, int itemSize) {
        int n = capacity.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0])
                return a[1] - b[1];

            return a[0] - b[0];
        }); // {cap, idx};
        for (int i = 0; i < n; i++) {
            pq.offer(new int[] { capacity[i], i });
        }

        int ans = -1;
        while (!pq.isEmpty()) {
            int c = pq.peek()[0];
            int id = pq.peek()[1];
            pq.poll();
            if (c >= itemSize) {
                ans = id;
                break;
            }
        }
        return ans;
    }
}