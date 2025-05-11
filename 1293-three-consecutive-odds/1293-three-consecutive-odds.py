class Solution(object):
    def threeConsecutiveOdds(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        n, mask, cnt = len(arr), (1 << 1), 0
        for i in range(n):
            if arr[i] & 1:
                cnt += 1
            else:
                cnt = 0
            
            if (((cnt & 1) != 0) and ((mask & cnt) != 0)):
                return True
        return False