class Solution(object):
    def areNumbersAscending(self, s):
        """
        :type s: str
        :rtype: bool
        """
        words = s.split()
        res = []
        for w in words:
            if w[0] > '0' and w[0] <= '9':
                res.append(int(w))
        
        for i in range(1, len(res)):
            if res[i] <= res[i - 1]:
                return False
            
        return True