class Solution(object):
    def splitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def isPrime(num):
            if num <= 1:
                return False
            for i in range(2, int(num ** 0.5) + 1):
                if num % i == 0:
                    return False
            return True

        n = len(nums)
        sumA, sumB = 0, 0
        for i in range(n):
            if isPrime(i):
                sumA += nums[i]
            else:
                sumB += nums[i]
        return abs(sumA - sumB)