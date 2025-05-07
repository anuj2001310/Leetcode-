#j
class Solution(object):
    def maxSum(self, grid, limits, k):
        """
        :type grid: List[List[int]]
        :type limits: List[int]
        :type k: int
        :rtype: int
        """
        ans = 0
        n , m = len(grid), len(grid[0])
        max_heap = []
        heapq.heapify(max_heap)
        for i in range(n):
            grid[i].sort(reverse = True)
            j = 0
            while j < m and limits[i]:
                heapq.heappush(max_heap, -grid[i][j])
                j += 1
                limits[i] -= 1
        
        while k and max_heap:
            ans += heapq.heappop(max_heap)
            k -= 1
        return -1 * ans