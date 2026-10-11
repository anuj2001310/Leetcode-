class Solution:
    def findMin(self, nums: list[int]) -> int:
        n = len(nums)
        low, high = 0, n - 1
        ans = inf

        while low <= high:
            mid = low + ((high - low) >> 1)
            if nums[low] <= nums[mid]:
                ans = min(ans, nums[low])
                low = mid + 1
            else:
                ans = min(ans, nums[mid])
                high = mid - 1
            
        return ans
