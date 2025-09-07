class Solution(object):
    def sumZero(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        a = []
        for i in range(1, n):
            a.append(i)
        a.append(-sum(a))
        return a