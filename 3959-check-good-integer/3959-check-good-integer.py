class Solution:
    def checkGoodInteger(self, n: int) -> bool:
        d = s = 0
        while n:
            r = n % 10
            n //= 10
            if r == 0:
                continue
            d += r
            s += r ** 2
        return s - d >= 50