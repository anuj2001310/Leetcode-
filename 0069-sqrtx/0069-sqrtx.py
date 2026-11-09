class Solution:
    def mySqrt(self, x: int) -> int:
        ans = 0
        l, h = 1, x
        while l <= h:
            m = l + ((h - l) >> 1)
            if m * m <= x:
                ans = m
                l = m + 1
            else:
                h = m - 1
        
        return ans