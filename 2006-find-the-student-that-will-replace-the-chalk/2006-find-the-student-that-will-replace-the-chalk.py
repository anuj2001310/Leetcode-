class Solution(object):
    def chalkReplacer(self, chalk, k):
        """
        :type chalk: List[int]
        :type k: int
        :rtype: int
        """
        remaining_after_com_rounds = k % sum(chalk)

        for i in range(len(chalk)):
            if remaining_after_com_rounds < chalk[i]:
                return i
            
            remaining_after_com_rounds -= chalk[i]
        
        return -1 #Safeguard, this will never execute