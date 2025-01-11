class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        n = len(s)
        if n < k:
            return False
        
        cnt = 0
        freq = Counter(s)

        for key, val in freq.items():
            if val & 1:
                cnt += 1
        
        if cnt > k:
            return False
        return True