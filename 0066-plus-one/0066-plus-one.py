class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[-1] < 9:
            digits[-1] += 1
            return digits
        
        astr = int(''.join([str(i) for i in digits])) + 1
        return [int(i) for i in str(astr)]