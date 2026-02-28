MOD = 10 ** 9 + 7
ans = [0] * (10 ** 5 + 1)
res = 0
length = -1
for i in range(1, 18):
    for e in range(2 ** (i - 1), min(2 ** i, len(ans))):
        res = ((res << i) | e) % MOD
        ans[e] = res


class Solution:
    def concatenatedBinary(self, n: int) -> int:
        return ans[n]
