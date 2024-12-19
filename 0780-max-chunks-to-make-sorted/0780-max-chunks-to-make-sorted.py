class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        c, m = 0, -1
        for idx, ele in enumerate(arr):
            m = max(m, ele)
            if m == idx:
                c += 1
        
        return c