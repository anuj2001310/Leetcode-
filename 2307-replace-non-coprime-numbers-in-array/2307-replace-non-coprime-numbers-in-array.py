class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = []

        i = 1
        res.append(nums[0])
        while i < n:
            check = nums[i]
            while res and gcd(check, res[-1]) > 1:
                val = res.pop()
                check = lcm(check, val)
            
            i += 1
            res.append(check)
        
        return res