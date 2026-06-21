class Solution:
    def consecutiveSetBits(self, n: int) -> bool:
        cnt, p = 0, -1
        while n:
            r = 1 if n & 1 else 0
            if r == 1 and r == p:
                cnt += 1
            
            p = r
            n >>= 1
        
        return cnt == 1
        
