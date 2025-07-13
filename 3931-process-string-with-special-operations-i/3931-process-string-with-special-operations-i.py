class Solution:
    def processStr(self, s: str) -> str:
        stack = []
        n = len(s)
        for i in range(n):
            ch = s[i]
            if ch >= 'a' and ch <= 'z':
                stack.append(ch)
                continue
            if stack and ch == '*':
                stack.pop()
            elif ch == '#':
                stack.extend(stack)
            elif ch == '%':
                stack.reverse()

        return ''.join(stack)