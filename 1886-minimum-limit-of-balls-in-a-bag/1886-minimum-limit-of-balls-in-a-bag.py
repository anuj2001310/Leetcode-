class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        l = 1
        r = max(nums)
        def helper(mid):
            c = 0
            for num in nums:
                c += (num - 1) // mid
            
            return c <= maxOperations

        while l < r:
            mid = l + (r - l) // 2

            if helper(mid):
                r = mid
            else:
                l = mid + 1
        return l