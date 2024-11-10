class Solution(object):
    def smallestNumber(self, n, t):
        """
        :type n: int
        :type t: int
        :rtype: int
        """
        while True:
            num = n
            pro = 1
            while num:
                pro *= (num % 10)
                num //= 10
            if pro % t == 0:
                return n
            n += 1
        