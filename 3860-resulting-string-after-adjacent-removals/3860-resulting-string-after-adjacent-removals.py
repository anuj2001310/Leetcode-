class Solution(object):
    def resultingString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []

        def func(ch):
            val = abs(ord(stack[-1]) - ord(ch))
            return val == 1 or val == 25
            
        for ch in s:
            if stack and func(ch):
                stack.pop()
            else:
                stack.append(ch)
                
        return ''.join(stack)