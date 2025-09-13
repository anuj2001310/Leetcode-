class Solution:
    def maxFreqSum(self, s: str) -> int:
        ch = Counter(s)
        vowels = 'aeiou'
        v, c = 0, 0
        for item, freq in ch.items():
            if item in vowels:
                v = max(v, freq)
            else:
                c = max(c, freq)
        
        return c + v