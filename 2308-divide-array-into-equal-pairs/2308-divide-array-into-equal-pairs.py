class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        vis = [False] * 501
        for num in nums:
            vis[num] = not vis[num]
        
        for v in vis:
            if v:
                return False
        return True