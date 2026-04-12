class Solution:
    def countDigitOccurrences(self, nums: list[int], digit: int) -> int:
        cnt = 0
        for num in nums:
            cnt = cnt + str(num).count(str(digit))
        
        return cnt