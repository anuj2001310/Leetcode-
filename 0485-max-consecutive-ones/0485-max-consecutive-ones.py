class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        cnt = mxcnt = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                cnt += 1
                mxcnt = max(cnt, mxcnt)
            else:
                cnt = 0
        return mxcnt