class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        pq = [-x for x in nums]
        heapify(pq)
        ans = 0
        for i in range(k):
            ans -= pq[0]
            heapreplace(pq, pq[0] // 3)
        return ans
