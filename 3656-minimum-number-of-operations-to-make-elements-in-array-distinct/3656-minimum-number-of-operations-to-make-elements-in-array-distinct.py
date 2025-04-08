class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        freq = [False for _ in range(128)]

        for i in range(n - 1, -1, -1):
            if freq[nums[i]]:
                return i // 3 + 1
            freq[nums[i]] = True
        
        return 0