class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        n = len(nums)
        vis = [0] * 101
        for num in nums:
            if num < k:
                return -1
            elif num > k:
                vis[num] += 1
        
        return sum(1 for v in vis if v)