class Solution:
    def countNegatives(self, nums: List[List[int]]) -> int:
        n, m = len(nums), len(nums[0])
        a = 0
        for i in range(n):
            for j in range(m):
                a += 1 if nums[i][j] < 0 else 0
        
        return a