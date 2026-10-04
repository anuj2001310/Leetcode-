class Solution:
    def search(self, nums: list[int], target: int) -> int:
        n = len(nums)
        l, h = 0, n - 1
        while l <= h:
            mid = l + ((h - l) >> 1)
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                h = mid - 1
            else:
                l = mid + 1
        
        return -1