class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        res = []
        for num in nums:
            original = num
            candidate = -1
            for j in range(1, original):
                if (j | (j + 1)) == original:
                    candidate = j
                    break
            res.append(candidate)
        return res