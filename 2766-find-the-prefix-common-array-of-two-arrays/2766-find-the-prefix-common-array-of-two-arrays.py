class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)

        res = []
        pa = [False for _ in range(n + 1)]
        pb = [False for _ in range(n + 1)]

        cnt = 0
        for i in range(n):
            cnt += 1 if A[i] == B[i] else 0
            cnt += 1 if pa[B[i]] else 0
            cnt += 1 if pb[A[i]] else 0

            pa[A[i]] = True
            pb[B[i]] = True

            res.append(cnt)
        return res