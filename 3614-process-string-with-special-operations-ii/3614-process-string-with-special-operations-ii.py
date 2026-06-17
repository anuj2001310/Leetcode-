class Solution:
    def processStr(self, s: str, k: int) -> str:
        L = 0
        for c in s:
            if c == "*":
                if L > 0:
                    L -= 1
            elif c == "#":
                L *= 2
            elif c == "%":
                pass
            else:
                L += 1
        if k >= L:
            return "."

        p = k
        for c in s[::-1]:
            if c == "*":
                L += 1
            elif c == "#":
                if p >= L // 2:
                    p -= L // 2
                L = L // 2
            elif c == "%":
                p = (L - 1) - p
            else:
                if L == p + 1:
                    return c
                L -= 1
        return s[p]
