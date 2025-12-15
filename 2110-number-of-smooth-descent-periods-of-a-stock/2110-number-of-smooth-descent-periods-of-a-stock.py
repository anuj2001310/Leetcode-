class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        ans, p = 1, 1
        n = len(prices)

        for i in range(1, n):
            if prices[i] == prices[i - 1] - 1:
                p += 1
            else:
                p = 1
            ans += p

        return ans