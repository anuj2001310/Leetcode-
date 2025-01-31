class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        rows = cols = len(grid)
        max_island = 0
        w, l, vis = 0, 1, 2
        def get_size (row, col) -> int:
            grid[row][col] = vis
            stack = [(row, col)]
            is_size = 0
            sh = set()
            dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
            while stack:
                row, col = stack.pop()
                is_size += 1
                for r, c in dirs:
                    nr = row + r
                    nc = col + c
                    if 0 <= nr < rows and 0 <= nc < cols:
                        ngh = grid[nr][nc]
                        if ngh == l:
                            stack.append((nr, nc))
                            grid[nr][nc] = vis
                        elif ngh <= w:
                            sh.add((nr, nc))
            
            for sr, sc in sh:
                grid[sr][sc] -= is_size
            return is_size
        
        for row in range(rows):

            for col in range(cols):
                if grid[row][col] != l:
                    continue
                max_island = max(max_island, get_size(row, col))
                if max_island == rows * cols:
                    return max_island
        
        if max_island == 0:
            return 1
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] < w:
                    val = grid[row][col]
                    max_island = max(max_island, -val + 1)
                    if max_island == rows * cols:
                        return max_island
        
        return max_island
