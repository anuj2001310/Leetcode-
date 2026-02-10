class Solution:
    def mergeAdjacent(self, nums: List[int]) -> List[int]:
        res = []
        for x in nums:
            curr = x
            while res and res[-1] == curr:
                curr *= 2
                res.pop()
            
            res.append(curr)
        
        return res