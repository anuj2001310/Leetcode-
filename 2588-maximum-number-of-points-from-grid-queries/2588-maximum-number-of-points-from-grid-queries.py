class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        n, m = len(grid), len(grid[0])
        k = len(queries)
        
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        ans = [0] * k
        
        vis = [[False] * m for _ in range(n)]
        
        pq = [(grid[0][0], 0, 0)]
        heapq.heapify(pq)

        query_pairs = [(val, idx) for idx, val in enumerate(queries)]
        query_pairs.sort()  
        
        vis[0][0] = True
        count = 0
        for thresh, idx in query_pairs:
            while pq and pq[0][0] < thresh:
                val, r, c = heapq.heappop(pq)
                count += 1
                
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    
                    if (0 <= nr < n and 0 <= nc < m and not vis[nr][nc]):
                        vis[nr][nc] = True
                        heapq.heappush(pq, (grid[nr][nc], nr, nc))
            
            ans[idx] = count
            
        return ans