class Solution(object):
    def findClosest(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: int
        """
        d1, d2 = abs(x - z), abs(y - z)
        return 1 if d1 < d2 else (0 if d1 == d2 else 2)