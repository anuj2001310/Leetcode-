class Solution:
    def calculateScore(self, instructions: List[str], values: List[int]) -> int:
        n = len(values)
        vis = [False] * n
        score, i = 0, 0
        while 0 <= i < n and not vis[i]:
            vis[i] = True
            if instructions[i] == "add":
                score += values[i]
                i += 1
            else:
                i += values[i]
        return score