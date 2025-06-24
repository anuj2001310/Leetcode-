class Solution:
    def checkPrimeFrequency(self, nums: List[int]) -> bool:
        n = len(nums)
        freq = [0] * 101

        def isPrime(num):
            if num <= 1:
                return False
            i = 2
            while i * i <= num:
                if num % i == 0:
                    return False
                i += 1

            return True
            
        for i in range(n):
            freq[nums[i]] += 1
            
        for i in range(101):
            
            if freq[i] == 0:
                continue
                
            if isPrime(freq[i]):
                return True
                
        return  False