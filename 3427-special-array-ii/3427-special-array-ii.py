class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
    
        if n == 1:
            return [True] * len(queries)  # Single element arrays are always special

        # Step 1: Create the special array
        special = [0] * (n - 1)
        for i in range(n - 1):
            if nums[i] & 1 == nums[i + 1] & 1:
                special[i] = 1

        # Step 2: Create the prefix_special array
        prefix_special = [0] * n
        for i in range(1, n):
            prefix_special[i] = prefix_special[i - 1] + special[i - 1]

        # Step 3: Evaluate each query using the prefix_special array
        result = []
        for fromi, toi in queries:
            if prefix_special[toi] - prefix_special[fromi] > 0:
                result.append(False)
            else:
                result.append(True)

        return result
    