class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        ans = inf
        n, m = len(nums1), len(nums2)

        i, j = 0, 0
        while i < n and j < m:
            if nums1[i] == nums2[j]:
                ans = nums1[i]
                break
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
            
        
        return -1 if ans == inf else ans