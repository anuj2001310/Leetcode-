class Solution:
    def maxProduct(self, num: int) -> int:
        n, m = 0, 0
        while num:
            r = num % 10
            if r >= n:
                m = n
                n = r
            elif r > m:
                m = r
            num //= 10

        return n * m