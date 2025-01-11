class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        n = len(s)
        if n < k:
            return False
            
        c = 0
        freq = Counter(s)
        for u, v in freq.items():
            if v & 1:
                c += 1
        
        if c > k:
            return False
        return True