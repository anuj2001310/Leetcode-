class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans, c = -1, 0
        for i in range(n):
            t = 0
            for g in grid[i]:
                if g:
                    t += 1
            
            if t > c:
                c = t
                ans = i
        
        return ans