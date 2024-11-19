class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        if k == 1:
            return max(nums)
        if n == k:
            return sum(nums) if len(set(nums)) == n else 0

        left, right = 0, 1
        result, t = 0, nums[0]

        visited = {nums[0]}

        while right < n:
            while nums[right] in visited:
                t -= nums[left]
                visited.remove(nums[left])
                left += 1
            
            t += nums[right]
            visited.add(nums[right])

            if right - left + 1 == k:
                result = max(result, t)
                t -= nums[left]
                visited.remove(nums[left])
                left += 1
            
            right += 1

        return result