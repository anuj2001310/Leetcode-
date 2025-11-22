class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        return sum(1 for i in range(len(nums)) if nums[i] % 3 != 0)