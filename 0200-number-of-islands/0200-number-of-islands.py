class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n, m = len(grid), len(grid[0])
        vis = [[False for _ in range(m)] for _ in range(n)]
        cnt = 0

        def dfs (r : int, c : int) -> void:
            if r < 0 or c < 0 or r >= n or c >= m or vis[r][c] or grid[r][c] == '0':
                return 
            vis[r][c] = True
            dfs (r - 1, c)
            dfs (r + 1, c)
            dfs (r, c - 1)
            dfs (r, c + 1)

            return 
            

        for r in range(n):
            for c in range(m):
                if not vis[r][c] and grid[r][c] == '1':
                    dfs (r, c)
                    cnt += 1
        

        return cnt