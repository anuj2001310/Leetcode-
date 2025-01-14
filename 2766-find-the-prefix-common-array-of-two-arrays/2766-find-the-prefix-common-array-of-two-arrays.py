class Solution(object):
    def findThePrefixCommonArray(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
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