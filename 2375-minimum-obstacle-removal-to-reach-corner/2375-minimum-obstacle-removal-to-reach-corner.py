import heapq

class Solution:
    def minimumObstacles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])

        # Directions: up, right, down, left
        dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

        # Initialize the result grid with large values
        res = [[float('inf')] * n for _ in range(m)]
        res[0][0] = 0

        # Min-heap priority queue for the Dijkstra-like algorithm
        pq = [(0, 0, 0)]  # (cost, row, col) -> starting point with 0 obstacles

        while pq:
            cost, r, c = heapq.heappop(pq)

            # If we have already found a better path, skip this one
            if cost > res[r][c]:
                continue

            # Explore all 4 directions
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc

                # Check bounds
                if 0 <= nr < m and 0 <= nc < n:
                    # If the cell has an obstacle, set weight to 1, else 0
                    w = 1 if grid[nr][nc] == 1 else 0

                    # If a better path is found, update the result and push to the queue
                    if cost + w < res[nr][nc]:
                        res[nr][nc] = cost + w
                        heapq.heappush(pq, (cost + w, nr, nc))

        # The result at the bottom-right corner
        return res[m - 1][n - 1]

        
        