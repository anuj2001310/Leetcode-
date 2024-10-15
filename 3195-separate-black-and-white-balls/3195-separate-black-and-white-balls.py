class Solution(object):
    def minimumSteps(self, s):
        """
        :type s: str
        :rtype: int
        """
        res, swaps = 0, 0
        for ch in s:
            if ch == '1':
                swaps += 1
            else:
                res += swaps
        return res 