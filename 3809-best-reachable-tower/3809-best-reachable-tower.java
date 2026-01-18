class Solution {
    public int[] bestTower(int[][] towers, int[] center, int radius) {
        int n = towers.length;

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) {
                if (a[1] == b[1])
                    return a[2] - b[2];
                return a[1] - b[1];
            }
            return b[0] - a[0];
        }); //{q, x, y}

        for (int i = 0; i < n; ++i) {
            int x = towers[i][0];
            int y = towers[i][1];
            int quality = towers[i][2];

            int dis = Math.abs(x - center[0]) + Math.abs(y - center[1]);
            if (dis <= radius)
                pq.offer(new int[] { quality, x, y });
        }
        if (pq.isEmpty())
            return new int[] { -1, -1 };

        return new int[] { pq.peek()[1], pq.peek()[2] };
    }
}