class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        res = []
        
        for i in range(n - 1):
            dis = prices[i]
            for j in range(i + 1, n):
                if prices[j] <= prices[i]:
                    dis = prices[i] - prices[j]
                    break
            res.append(dis)

        res.append(prices[n - 1])
        return res