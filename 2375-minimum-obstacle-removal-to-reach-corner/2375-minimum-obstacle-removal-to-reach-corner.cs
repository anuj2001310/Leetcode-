using System;
using System.Collections.Generic;

public class Solution {
    // Directions: up, right, down, left
    private static readonly int[,] dirs = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    public int MinimumObstacles(int[][] grid) {
        int m = grid.Length;
        int n = grid[0].Length;

        // Initialize the result grid with large values
        int[, ] res = new int[m, n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                res[i, j] = int.MaxValue;  // Initialize all cells with infinity
        }

        // Min-heap priority queue for the Dijkstra-like algorithm
        var pq = new PriorityQueue<Cell, int>(); // Min-heap (cost, row, col)
        pq.Enqueue(new Cell(0, 0, 0), 0); // (cost, row, col) -> starting point with 0 obstacles
        res[0, 0] = 0;

        while (pq.Count > 0) {
            var current = pq.Dequeue();
            int cost = current.Cost;
            int r = current.Row;
            int c = current.Col;

            // If the cost is greater than the best-known cost, skip this cell
            if (cost > res[r, c]) 
                continue;

            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i, 0];
                int nc = c + dirs[i, 1];

                // Check bounds
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // If the cell has an obstacle, set weight to 1, else 0
                    int w = grid[nr][nc] == 1 ? 1 : 0;

                    // If a better path is found, update the result and push to the queue
                    if (cost + w < res[nr, nc]) {
                        res[nr, nc] = cost + w;
                        pq.Enqueue(new Cell(cost + w, nr, nc), cost + w);
                    }
                }
            }
        }

        // Return the result at the bottom-right corner
        return res[m - 1, n - 1];
    }

    // Helper class to represent a cell in the grid
    public class Cell {
        public int Cost { get; }
        public int Row { get; }
        public int Col { get; }

        public Cell(int cost, int row, int col) {
            Cost = cost;
            Row = row;
            Col = col;
        }
    }
}
