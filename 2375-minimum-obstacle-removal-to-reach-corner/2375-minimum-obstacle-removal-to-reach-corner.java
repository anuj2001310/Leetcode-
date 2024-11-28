class Solution {
    // Define a Pair to store cost and coordinates
    class Pair {
        int cost;
        int row;
        int col;

        Pair(int cost, int row, int col) {
            this.cost = cost;
            this.row = row;
            this.col = col;
        }
    }

    // Directions: up, right, down, left
    private final int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public int minimumObstacles(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // Initialize the result grid with large values
        int[][] res = new int[m][n];
        for (int[] row : res) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // Min-heap priority queue for the Dijkstra-like algorithm
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(p -> p.cost));

        // Starting point (0, 0) with 0 obstacles
        pq.offer(new Pair(0, 0, 0));
        res[0][0] = 0;

        while (!pq.isEmpty()) {
            Pair current = pq.poll();
            int cost = current.cost;
            int r = current.row;
            int c = current.col;

            // If we have already found a better path, skip this one
            if (cost > res[r][c])
                continue;

            // Explore all 4 directions
            for (int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                // Check bounds
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // If the cell has an obstacle, set weight to 1, else 0
                    int w = (grid[nr][nc] == 1) ? 1 : 0;

                    // If a better path is found, update the result and push to the queue
                    if (cost + w < res[nr][nc]) {
                        res[nr][nc] = cost + w;
                        pq.offer(new Pair(cost + w, nr, nc));
                    }
                }
            }
        }

        // The result at the bottom-right corner
        return res[m - 1][n - 1];
    }
}