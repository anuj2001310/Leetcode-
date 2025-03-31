class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        p = [0] * (len(weights) - 1)
        for i in range(len(weights) - 1):
            p[i] += weights[i] + weights[i + 1]
        p.sort()
        return sum(p[len(weights) - i - 2] - p[i] for i in range(k - 1))