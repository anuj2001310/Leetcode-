class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        map = {}
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                map[nums[i] * nums[j]] = map.get(nums[i] * nums[j], 0) + 1  

        return sum(((w * (w - 1)) * 4) for w in map.values() if w > 1)