class Solution:
    def numSub(self, str: str) -> int:
        mod = 10 ** 9 + 7
        n = len(str)
        t, s = 0, 0
        r = 0
        ans = 0

        while r < n:
            if str[r] == '1':
                t += 1
                s = max(t, s)
            
            elif str[r] == '0':
                ans = (ans + (s * (s + 1)) // 2) % mod
                t = 0
                s = 0
        
            r += 1
        
        ans = (ans + (s * (s + 1)) // 2) % mod
        return ans