class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        sq = sorted([x * x for x in nums], reverse = True)
        n = (len(nums) + 1) // 2
        return sum(sq[: n]) - sum(sq[n : ])