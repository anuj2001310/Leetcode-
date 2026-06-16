class Solution:
    def processStr(self, s: str) -> str:
        stack = []
        n = len(s)
        for i in range(n):
            c = s[i]
            if c == '*':
                stack = stack[: -1]
            elif c == '#':
                stack += stack
            elif c == '%':
                stack = stack[:: -1]
            else:
                stack.append(c)

        return ''.join(stack)
    