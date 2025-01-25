class Solution(object):
    def lexicographicallySmallestArray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: List[int]
        """
        n = len(nums)
        ordered_nums = sorted(nums)
        prev = ordered_nums[0]
        num_to_group = {}
        current_group = 0
        group_start = [0]

        for i, x in enumerate(ordered_nums):
            if x - prev > limit:
                current_group += 1
                group_start.append(i)

            num_to_group[x] = current_group
            prev = x
            
        result = []
        for x in nums:
            group = num_to_group[x]
            result.append(ordered_nums[group_start[group]])
            group_start[group] += 1

        return result
