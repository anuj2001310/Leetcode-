class Solution:
    def minOperations(self, nums: List[int]) -> int:
        result = 0
        stack = [0]

        for num in nums:
            if num > stack[-1]:
                stack.append(num)
            else:
                while num < stack[-1]:
                    result += 1
                    stack.pop()

                if stack[-1] != num:
                    stack.append(num)

        return result + len(stack) - 1
