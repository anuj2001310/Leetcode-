class Solution:
    @functools.cache
    def maxA(self, n: int) -> int:
        if n <= 5:
            return n
        else:
            return max(n, max(i * self.maxA(n - i - 1) for i in [3, 4, 5, 6]))
