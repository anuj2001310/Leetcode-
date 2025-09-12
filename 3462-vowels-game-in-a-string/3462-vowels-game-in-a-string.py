class Solution:
    def doesAliceWin(self, s: str) -> bool:
        h = 'aeiou'
        for ch in s:
            if ch in h:
                return True
        
        return False