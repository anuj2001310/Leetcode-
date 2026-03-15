class Solution:
    def countCommas(self, n: int) -> int:
        if n < 999:
            return 0
        
        return (n - 1000) + 1
        
