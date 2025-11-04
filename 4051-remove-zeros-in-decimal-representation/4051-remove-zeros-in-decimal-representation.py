class Solution:
    def removeZeros(self, n: int) -> int:
        ans = 0
        for ch in str(n):
            if ch == "0":
                continue
            num = ord(ch) - 48
            ans = ans * 10 + num
        return ans