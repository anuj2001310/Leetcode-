class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        maximum, minimum = -inf, inf
        vis = [False] * 101
        
        for i in range(n):
            maximum = max(maximum, nums[i])
            minimum = min(minimum, nums[i])
            vis[nums[i]] = True

        res = []
        for i in range(minimum, maximum):
            if not vis[i]:
                res.append(i)

        return res
        