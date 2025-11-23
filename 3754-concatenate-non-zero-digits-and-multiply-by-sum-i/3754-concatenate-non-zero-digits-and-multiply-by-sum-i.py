class Solution:
    def sumAndMultiply(self, n: int) -> int:
        st = str(n)
        sum_of_dig = 0
        res = 0
        for ch in st:
            if ch == '0':
                continue
            sum_of_dig = sum_of_dig + (ord(ch) - 48)
            res = res * 10 + (ord(ch) - 48)
        
        return res * sum_of_dig