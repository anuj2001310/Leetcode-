class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        ans, prev = 0, 0
        for layer in bank:
            cnt = layer.count("1")
            if cnt == 0:
                continue
            
            ans += prev * cnt
            prev = cnt
        
        return ans