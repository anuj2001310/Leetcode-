class Solution:
    def passwordStrength(self, password: str) -> int:
        cnt = 0
        n = len(password)
        vis = set()
        symbol = '!@#$'

        for i in range(n):
            ch = password[i]
            if ch in vis:
                continue
            
            if ch.islower():
                cnt += 1
            elif ch.isupper():
                cnt += 2
            elif ch.isdigit():
                cnt += 3
            else:
                cnt += 5
            
            vis.add(ch)
        
        return cnt