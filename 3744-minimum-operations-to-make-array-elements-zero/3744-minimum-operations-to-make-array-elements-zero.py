class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        intervals = []
        for d in range(1, 16):
            low = 4 ** (d - 1)
            high = 4 ** d - 1
            intervals.append((low, high, d))
        
        result = 0
        for l, r in queries:
            total_depth = 0
            for low, high, d in intervals:
                if l > high:
                    continue
                if r < low:
                    break
                low_actual = max(l, low)
                high_actual = min(r, high)
                if low_actual <= high_actual:
                    count = high_actual - low_actual + 1
                    total_depth += count * d
            result += (total_depth + 1) // 2
        return result