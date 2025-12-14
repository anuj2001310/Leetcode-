class Solution(object):
    def absDifference(self, arr, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        arr.sort()
        return sum(arr[-k: ]) - sum(arr[: k])