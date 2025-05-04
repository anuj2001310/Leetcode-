class Solution(object):
    def maxProduct(self, n):
        """
        :type n: int
        :rtype: int
        """
        arr = []
        while n:
            arr.append(n % 10)
            n //= 10
        arr.sort()
        return arr[-1] * arr[-2]