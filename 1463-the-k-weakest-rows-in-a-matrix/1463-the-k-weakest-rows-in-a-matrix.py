class Solution(object):
    def kWeakestRows(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        n, m = len(mat), len(mat[0])
        minheap = []
        heapq.heapify(minheap)

        for i in range(n):
            s = sum(mat[i])
            heapq.heappush(minheap, (s, i))
        
        ans = []
        while k and minheap:
            top = heapq.heappop(minheap)
            ans.append(top[1])
            k -= 1
        return ans