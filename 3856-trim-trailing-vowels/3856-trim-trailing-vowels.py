class Solution:
    def trimTrailingVowels(self, s: str) -> str:
        n = len(s)
        i = n - 1
        v = 'aeiou'
        while i >= 0:
            if s[i] not in v:
                break
            i -= 1
        
        return s[: i + 1]