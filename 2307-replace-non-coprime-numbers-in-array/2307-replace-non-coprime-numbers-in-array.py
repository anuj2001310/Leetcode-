class Solution:
    #def gcd(self, a : int, b : int) -> int:
        #return a if b == 0 else self.gcd(b, a % b)

    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n == 1:
            return nums


        stack = []
        
        stack.append(nums[0])
        i = 1
        while i < n:
            checkwith = nums[i]
            while stack and gcd(checkwith, stack[-1]) > 1:
                val = stack.pop()
                checkwith = lcm(checkwith, val)
            
            i += 1
            stack.append(checkwith)
        
        return stack