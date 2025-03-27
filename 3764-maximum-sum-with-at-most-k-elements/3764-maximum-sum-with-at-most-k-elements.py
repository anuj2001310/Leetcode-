from heapq import heappop, heappush, heapify

class Solution:
    def maxSum(self, grid: List[List[int]], limits: List[int], k: int) -> int:
        maxheap = []
        heapq.heapify(maxheap)

        n, m = len(grid), len(grid[0])
        for i in range(n):
            grid[i].sort(reverse = True)
            j = 0
            while j < m and limits[i]:
                heapq.heappush(maxheap, -grid[i][j])
                limits[i] -= 1
                j += 1
        
        ans = 0

        while k and maxheap:
            ans += heapq.heappop(maxheap)
            k -= 1
        return -1 * ans
