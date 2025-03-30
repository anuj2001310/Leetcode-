class Solution:
    def reverseDegree(self, s: str) -> int:
        return sum(((26 - (ord(s[i]) - ord('a'))) * (i + 1)) for i in range(len(s)))