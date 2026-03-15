class Solution:
    def countCommas(self, n: int) -> int:
        if n < 999:
            return 0
        
        cnt = 0
        p = 1000
        while p <= n:
            cnt += (n - p + 1)
            p *= 1000
        return cnt