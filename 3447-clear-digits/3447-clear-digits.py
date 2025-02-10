class Solution(object):
    def clearDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        for char in s:
            if not char.isdigit():
                stack.append(char)
            elif stack:
                stack.pop()
        return ''.join(stack)