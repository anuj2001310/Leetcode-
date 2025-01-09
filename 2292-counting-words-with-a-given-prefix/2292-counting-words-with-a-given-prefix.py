class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        cnt = 0
        for st in words:
            if st.startswith(pref):
                cnt += 1
        
        return cnt