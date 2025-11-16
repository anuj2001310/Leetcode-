class Solution(object):
    def numSub(self, s):
        """
        :type s: str
        :rtype: int
        """
        substring = s.split('0')
        MOD = 10 ** 9 + 7
        ANS = 0

        for substr in substring:
            count = len(substr)
            ANS = (ANS + (count * (count + 1)) // 2) % MOD
        
        return ANS