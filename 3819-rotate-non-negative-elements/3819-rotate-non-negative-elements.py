class Solution:
    def rotateElements(self, nums: List[int], k: int) -> List[int]:
        m, n = 0, len(nums)
        a = [0] * n

        for num in nums:
            if num >= 0:
                a[m] = num
                m += 1
        
        if m == 0:
            return nums
        
        k %= m
        i, j = 0, 0

        while i < n:
            if nums[i] >= 0:
                nums[i] = a[(j + k) % m]
                j += 1
            i += 1
        return nums