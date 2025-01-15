class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        bc = bin(num2).count('1')
        bc -= bin(num1).count('1')
        cur = 1
        while bc != 0:
            if bc < 0 and (num1 & cur) != 0:
                num1 ^= cur
                bc += 1
            elif bc > 0 and (num1 & cur) == 0:
                num1 |= cur
                bc -= 1
            cur <<= 1
        return num1
