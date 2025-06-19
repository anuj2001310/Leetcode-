class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        max_val = -inf
        min_val = inf
        cnt = 1
        n = len(nums)

        nums.sort()
        for i in range(n):
            min_val = min(min_val, nums[i])
            max_val = max(max_val, nums[i])
            if max_val - min_val > k:
                cnt += 1
                min_val = nums[i]
        
        return cnt