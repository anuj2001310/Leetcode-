class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        pid = -1
        mi = 0
        mx = 0
        res = []
        while mx < len(nums):
            if (mx - mi) + 1 == k:
                if pid < mi:
                    res.append(nums[mx])
                else:
                    res.append(-1)
                nmx = mx + 1
                if nmx < len(nums) and nums[nmx] != nums[mx] + 1: 
                    pid = mx
                mx = nmx
                mi += 1
            else:
                nmx = mx + 1
                if nmx < len(nums) and nums[nmx] != nums[mx] + 1:
                    pid = mx
                mx = nmx
        
        return res