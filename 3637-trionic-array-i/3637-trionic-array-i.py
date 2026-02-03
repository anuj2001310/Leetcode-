class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        state = 0

        for i in range(len(nums) - 1):
            if nums[i+1] > nums[i]:
                state |= 1
            elif nums[i+1] < nums[i] and (state == 1 or state == 2):
                state = 2
            else:
                return False
        
        return state == 3