class Solution(object):
    def peopleAwareOfSecret(self, n, delay, forget):
        """
        :type n: int
        :type delay: int
        :type forget: int
        :rtype: int
        """
        dp = [0] * (n + 1)

        #vector<long> dp(n + 1);
        dp[1] = 1
        share, mod, res = 0, 10 ** 9 + 7, 0
        for i in range(2, n + 1):
            dp[i] = share = (share + dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + mod) % mod
        
        for i in range(n - forget + 1, n + 1):
            res = (res + dp[i]) % mod


        return res