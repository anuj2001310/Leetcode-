class Solution(object):
    def maxFreqSum(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        freq = [0 for _ in range(26)]
        v, c = 0, 0
        for ch in s:
            idx = ord(ch) - ord('a')
            freq[idx] += 1

        def isVowel(ch):
            return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'

        
        for i in range(n):
            idx = ord(s[i]) - ord('a')
            if isVowel(s[i]):
                v = max(v, freq[idx])
            else:
                c = max(c, freq[idx])
        return v + c