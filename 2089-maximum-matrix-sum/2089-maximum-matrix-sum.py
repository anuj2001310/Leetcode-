class Solution(object):
    def maxMatrixSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        total_sum = 0
        negative_count = 0 
        minel = float('inf')
        for i in matrix:
            for j in i:
                if j < 0:
                    j *= -1
                    negative_count += 1
                total_sum += j
                if j < minel:
                    minel = j
        if negative_count & 1 == 0:
            return total_sum
        else:
            return total_sum - 2 * minel