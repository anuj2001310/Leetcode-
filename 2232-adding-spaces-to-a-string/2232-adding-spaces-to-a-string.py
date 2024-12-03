class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        res = ""
        i , k = 0, 0
        while i < len(s) and k < len(spaces):
            if i == spaces[k]:
                res += " "
                k += 1
            res += s[i]
            i += 1
        
        while i < len(s):
            res += s[i]
            i += 1
        
        return res