class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        if num == 0 or num == 1:
            return not num
        for i in range(num):
            s = str(i)
            if int(s) + int(s[:: - 1]) == num:
                return True
        
        return False