class Solution:
    def toggleLightBulbs(self, bulbs: list[int]) -> list[int]:
        n = len(bulbs)
        freq = [False for _ in range(101)]


        for i in range(n):
            if freq[bulbs[i]]:
                freq[bulbs[i]] = False
            else:
                freq[bulbs[i]] = True
            
        ans = []
        for i in range(101):
            if freq[i]:
                ans.append(i)
        
        return ans