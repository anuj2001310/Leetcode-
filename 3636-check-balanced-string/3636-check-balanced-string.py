class Solution:
    def isBalanced(self, num: str) -> bool:
        e, o = 0, 0
        for i in range(len(num)):
            dig = ord(num[i]) - ord('0')
            if i & 1:
                e += dig
            else:
                o += dig
        
        return e == o