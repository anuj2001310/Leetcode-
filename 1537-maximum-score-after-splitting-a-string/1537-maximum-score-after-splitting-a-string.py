class Solution(object):
    def maxScore(self, s):
        """
        :type s: str
        :rtype: int
        """
        from collections import Counter
        q = Counter(s)

        scoreLeft = 0
        scoreRight = q['1']
        if s[0] == '0':
            scoreLeft += 1
        else:
            scoreRight -= 1
        maxScore = scoreLeft + scoreRight

        for i in range(1,len(s)-1):
            if s[i] == '0':
                scoreLeft += 1
                maxScore = max(maxScore, scoreLeft + scoreRight)
            else:
                scoreRight -= 1

        return maxScore