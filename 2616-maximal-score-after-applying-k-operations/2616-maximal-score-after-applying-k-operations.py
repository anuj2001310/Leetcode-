class Solution(object):
    def maxKelements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        pq = [-x for x in nums]
        heapify(pq)
        ans = 0 
        for i in range(k): 
            ans -= pq[0] 
            heapreplace(pq, pq[0] // 3)
        return ans