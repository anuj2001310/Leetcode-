class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        arr_lens = []
        curr_len = 0
        for idx, num in enumerate(nums):
            if idx == 0:
                curr_len = 1
            elif num <= nums[idx - 1]:
                arr_lens.append(curr_len)
                curr_len = 1
            elif num > nums[idx - 1]:
                curr_len += 1
        arr_lens.append(curr_len)
        if len(arr_lens) == 1:
            return arr_lens[0] // 2
        candidate1 = max(arr_lens) // 2
        candidate2 = -1
        i, j = 0, 1
        while j < len(arr_lens):
            if min(arr_lens[i], arr_lens[j]) > candidate2:
                candidate2 = min(arr_lens[i], arr_lens[j])
            i += 1
            j += 1
        return max(candidate1, candidate2)
