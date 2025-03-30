class Solution(object):
    def reverseDegree(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum((26 - (ord(s[x]) - ord('a'))) * (x + 1) for x in range(len(s)))