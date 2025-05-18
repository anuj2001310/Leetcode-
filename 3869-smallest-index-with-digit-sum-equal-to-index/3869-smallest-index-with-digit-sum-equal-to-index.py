class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            if sum(int(x) for x in str(nums[i])) == i:
                return i
        return -1