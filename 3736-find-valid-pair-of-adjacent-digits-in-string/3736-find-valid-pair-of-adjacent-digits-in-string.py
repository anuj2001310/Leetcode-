class Solution:
    def findValidPair(self, s: str) -> str:
        res = [0] * 10
        n = len(s)
        for ch in s:
            res[ord(ch) - ord('0')] += 1
        for i in range(1, n):
            cur = ord(s[i]) - ord('0')
            pre = ord(s[i - 1]) - ord('0')
            if cur == res[cur] and pre == res[pre] and pre != cur:
                return "" + s[i - 1] + s[i]
        
        return ""