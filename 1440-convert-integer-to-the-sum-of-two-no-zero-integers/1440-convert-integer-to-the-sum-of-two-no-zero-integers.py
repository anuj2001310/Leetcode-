class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1, n):
            a = i
            b = n - i
            if '0' in str(a) or '0' in str(b):
                continue
            return [a, b]
