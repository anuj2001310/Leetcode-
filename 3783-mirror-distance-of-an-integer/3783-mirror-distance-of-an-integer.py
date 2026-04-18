class Solution:
    def mirrorDistance(self, n: int) -> int:
        rev = 0
        num = n
        while num:
            r = num % 10
            rev = 10 * rev + r
            num //= 10
        
        return abs(n - rev)