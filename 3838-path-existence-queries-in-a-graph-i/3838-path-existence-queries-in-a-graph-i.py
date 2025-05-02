class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        q = len(queries)
        comp = [0] * n
        cid = 0
        for i in range(1, n):
            if nums[i] - nums[i - 1] <= maxDiff:
                comp[i] = cid
            else:
                cid += 1
                comp[i] = cid
        idx = 0
        ans = [False for _ in range(q)]
        for u, v in (queries):
            ans[idx] = (comp[u] == comp[v])
            idx += 1
        return ans