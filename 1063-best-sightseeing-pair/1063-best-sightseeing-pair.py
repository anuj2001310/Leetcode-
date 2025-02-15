class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n = len(values)
        ms, ml = 0, values[0]
        
        for j in range(1, n):
            ms = max(ms, ml + values[j] - j)
            ml = max(ml, values[j] + j)
        
        return ms