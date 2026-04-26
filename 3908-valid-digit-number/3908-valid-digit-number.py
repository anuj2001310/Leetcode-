class Solution:
    def validDigit(self, n: int, x: int) -> bool:
        return False if str(n)[0] == str(x) else (str(x) in str(n))