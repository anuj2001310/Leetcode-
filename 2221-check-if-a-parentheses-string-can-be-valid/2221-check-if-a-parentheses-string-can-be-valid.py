class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        n = len(s)
        if n & 1:
            return False
        
        open = []
        close = []
        for i in range(n):
            if locked[i] == "0":
                close.append(i)
            elif s[i] == "(":
                open.append(i)
            elif s[i] == ")":
                if open:
                    open.pop()
                elif close:
                    close.pop()
                else:
                    return False
        
        while open and close and open[-1] < close[-1]:
            open.pop()
            close.pop()
        
        if open:
            return False
        return True