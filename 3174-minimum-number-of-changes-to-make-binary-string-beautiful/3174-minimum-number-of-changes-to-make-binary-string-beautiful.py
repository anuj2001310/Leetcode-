class Solution(object):
    def minChanges(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum(1 for i in range(1, len(s), 2) if s[i - 1] != s[i])