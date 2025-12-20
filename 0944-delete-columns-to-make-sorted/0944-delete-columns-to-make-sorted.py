class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs)
        word_len = len(strs[0])
        c = 0

        for i in range(word_len):
            prev = strs[0][i]
            for j in range(n):
                if prev > strs[j][i]:
                    c += 1
                    break

                else:
                    prev = strs[j][i]

        return c
