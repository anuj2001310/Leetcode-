class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        ans = 0
        if n2 & 1 == 1:
            for ele in nums1:
                ans ^= ele
        
        if n1 & 1 == 1:
            for ele in nums2:
                ans ^= ele
        
        return ans