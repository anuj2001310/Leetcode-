class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = []
        for i in range(1, n):
            ans.append(i)
        ans.append(-sum(ans))
        return ans