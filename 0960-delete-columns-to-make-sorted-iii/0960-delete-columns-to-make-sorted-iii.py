class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        """
        :type strs: List[str]
        :rtype: int
        """
        n = len(strs)
        m = len(strs[0])
        
        def help(i, j):
            for r in range(n):
                if strs[r][i] > strs[r][j]:
                    return False
            return True
        dp = [1] * m
        for j in range(1,m):
            for i in range(j):
                if help(i,j):
                    dp[j] = max(dp[j],dp[i] + 1)

        return m - max(dp)