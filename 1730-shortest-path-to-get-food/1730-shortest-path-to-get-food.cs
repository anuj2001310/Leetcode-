using System;
using System.Collections.Generic;

public class Solution {
    public int GetFood(char[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        
        int[][] dirs = new int[][] {
            new int[] {-1, 0},
            new int[] {0, 1},
            new int[] {1, 0},
            new int[] {0, -1}
        };
        
        var vis = new bool[n, m];
        var q = new Queue<(int, int, int)>();
        
        // Find  position of '*'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') {
                    q.Enqueue((0, i, j));
                    vis[i, j] = true;
                    break;
                }
            }
            if (q.Count > 0) break;
        }
        
        while (q.Count > 0) {
            var (t, r, c) = q.Dequeue();
            
            if (grid[r][c] == '#')
                return t;
            
            
            foreach (var d in dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !vis[nr, nc] &&
                    grid[nr][nc] != 'X') {
                    
                    vis[nr, nc] = true;
                    q.Enqueue((t + 1, nr, nc));
                }
            }
        }
        
        return -1;
    }
}