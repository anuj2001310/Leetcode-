class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        astr = int(''.join([str(i) for i in digits])) + 1
        return [int(i) for i in str(astr)]

        