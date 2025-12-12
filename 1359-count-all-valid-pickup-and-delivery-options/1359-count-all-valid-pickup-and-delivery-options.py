class Solution:
    def countOrders(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        if n <= 1:
            return n
        
        ans = 1
        for i in range(2, n + 1):
            ans = (ans * (2 * i - 1) * i) % MOD
        
        return ans