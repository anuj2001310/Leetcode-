class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        r = []
        for i in range(n):
            j = (i + nums[i] + n) % n
            r.append(nums[j])
        return r