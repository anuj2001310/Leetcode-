class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        curr, mn, mx = 0, 0, 0
        for d in differences:
            curr += d
            mn = min(mn, curr)
            mx = max(mx, curr)
            if (upper - mx) - (lower - mn) + 1 <= 0: return 0
        
        return upper - mx - lower + mn + 1
