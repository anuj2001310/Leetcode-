class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        freq = [0] * 32

        def dp(n):
            for i in range(32):
                m = 1 << i
                if m & n:
                    freq[i] += 1

        for ele in candidates:
            dp(ele)

        return max(freq)
