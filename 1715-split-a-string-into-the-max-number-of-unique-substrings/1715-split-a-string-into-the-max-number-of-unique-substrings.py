class Solution(object):
    def maxUniqueSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        N = len(s)
        self.ans = 0
        seen = set()

        def go(i, count):
            if count + (N - i) <= self.ans:
                return
            if i == N:
                self.ans = max(self.ans, count)
            
            for j in range(i + 1, N + 1):
                sub_str = s[i:j]
                if sub_str not in seen:
                    seen.add(sub_str)
                    go(j, count + 1)
                    seen.remove(sub_str)
            return
        
        go(0, 0)
        return self.ans