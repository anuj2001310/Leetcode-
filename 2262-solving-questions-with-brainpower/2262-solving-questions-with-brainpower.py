class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        dp = [-1] * (n + 1)

        def memo(idx: int) -> int:
            if idx >= n:
                return 0
            if dp[idx] != -1:
                return dp[idx]
            
            take = questions[idx][0]
            nidx = idx + questions[idx][1] + 1
            if nidx < n:
                take += memo(nidx)
            skip = memo(idx + 1)

            dp[idx] = max(take, skip)
            return dp[idx]
            
        return memo(0)