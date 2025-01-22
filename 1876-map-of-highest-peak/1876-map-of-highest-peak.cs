using System;
using System.Collections.Generic;

public class Solution {
    // Direction vectors: up, right, down, left
    private static int[][] dirs = new int[][] { new int[] { -1, 0 }, new int[] { 0, 1 }, new int[] { 1, 0 }, new int[] { 0, -1 } };

    public class Pair {
        public int First { get; set; }
        public int Second { get; set; }

        public Pair(int first, int second) {
            First = first;
            Second = second;
        }
    }

    public int[][] HighestPeak(int[][] isWater) {
        int n = isWater.Length;        
        int m = isWater[0].Length;    
        int[][] height = new int[n][];
        
        for (int i = 0; i < n; i++) {
            height[i] = new int[m];
            for (int j = 0; j < m; j++) {
                height[i][j] = -1;
            }
        }

        var queue = new Queue<Pair>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    queue.Enqueue(new Pair(i, j));
                    height[i][j] = 0;
                }
            }
        }

        while (queue.Count > 0) {
            Pair current = queue.Dequeue();
            int r = current.First;
            int c = current.Second;

            foreach (var dir in dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && height[nr][nc] == -1) {
                    height[nr][nc] = height[r][c] + 1;
                    queue.Enqueue(new Pair(nr, nc));
                }
            }
        }

        return height;
    }
}
