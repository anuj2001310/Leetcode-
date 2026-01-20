class Solution:
    def vowelConsonantScore(self, s: str) -> int:
        def vowel(ch) -> bool:
            h = 'aeiou'
            if ch in h:
                return True
            return False
        
        def cons(ch):
            if ch >= 'a' and ch <= 'z' and not vowel(ch):
                return True
            
            return False
        
        n = len(s)
        v = c = 0
        for i_ in range(n):
            if vowel(s[i_]):
                v += 1
            if cons(s[i_]):
                c += 1
        
        score = 0 if  c == 0 else v // c
        return score