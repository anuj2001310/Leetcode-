class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)

        dp = [[-1 for _ in range(((sum(nums) >> 1) + 1))] for _ in range(n)]
        
        #print(dp)
        def memo(nums, dp, sm, idx):
            if sm == 0:
                return True
            
            if idx >= len(nums):
                return False

            if dp[idx][sm] != -1:
                return  True if dp[idx][sm] == 1 else False

            pick, non_pick = False, False

            if nums[idx] <= sm:
                pick = memo(nums, dp, sm - nums[idx], idx + 1)

            non_pick = memo(nums, dp, sm, idx + 1)

            dp[idx][sm] = 1 if pick or non_pick else 0

            return True if dp[idx][sm] == 1 else False


        return False if (sum(nums) & 1) else memo(nums, dp, sum(nums) >> 1, 0)