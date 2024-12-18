class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        maps = {}
        for ele in nums:
            maps[ele] = maps.get(ele, 0) + 1
        
        queue = []
        nums_d = set(nums)
        for num in nums_d:
            heapq.heappush(queue, (-maps[num], num))
        
        ans = []
        while len(ans) < k:
            ans.append(queue[0][1])
            heapq.heappop(queue)
        return ans