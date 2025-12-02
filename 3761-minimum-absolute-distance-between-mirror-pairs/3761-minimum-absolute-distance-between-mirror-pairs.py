class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        n = len(nums)
        ans = inf
        Map = {}
        r = 0

        def reverse(num : int) -> int:
            rev = 0
            while num:
                rev = 10 * rev + num % 10
                num //= 10
            
            return rev

        while r < n:
            if nums[r] in Map:
                ans = min(ans, r - Map[nums[r]])
            
            rev = reverse(nums[r])
            Map[rev] = r
            r += 1
        
        return -1 if ans == inf else ans