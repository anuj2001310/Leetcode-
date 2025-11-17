class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        q = collections.deque()
        n = len(nums)

        for i in range(n):
            if nums[i] == 0:
                continue
            
            if q and i - q.popleft() <= k:
                return False
            
            if nums[i] == 1:
                q.append(i)
        
        return True