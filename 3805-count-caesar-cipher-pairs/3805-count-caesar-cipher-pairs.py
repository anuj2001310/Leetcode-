class Solution:
    def countPairs(self, words: List[str]) -> int:
        seen = {}
        ans = 0
        for w in words:
            head = ord(w[0])
            key = tuple((ord(c) - head) % 26 for c in w)
            cnt = seen.get(key, 0)
            ans += cnt
            seen[key] = cnt + 1
        return ans