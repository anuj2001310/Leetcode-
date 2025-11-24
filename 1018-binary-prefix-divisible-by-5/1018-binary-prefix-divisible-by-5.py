class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        n = len(nums)
        ans = [False for _ in range(n)]
        num = 0
        for i in range(n):
            num = ((num << 1) + nums[i]) % 5
            ans[i] = (num == 0)
        
        return ans