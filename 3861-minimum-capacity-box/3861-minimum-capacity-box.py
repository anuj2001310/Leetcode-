class Solution:
    def minimumIndex(self, capacity: list[int], itemSize: int) -> int:
        n = len(capacity)
        h = []

        for i in range(n):
            h.append([capacity[i], i])
        
        h.sort(key = lambda x : x[0])
        ans = -1

        for i in range(n):
            [c, idx] = h[i]
            if c >= itemSize:
                ans = idx
                break
        
        return ans