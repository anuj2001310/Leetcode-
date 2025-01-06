class Solution(object):
    def minOperations(self, boxes):
        """
        :type boxes: str
        :rtype: List[int]
        """
        n = len(boxes)
        res = [0] * n

        balls, moves = 0, 0
        for i in range(n):
            res[i] = (balls + moves)
            moves += balls
            balls += (ord(boxes[i]) - ord('0'))
        
        balls, moves = 0, 0
        for i in reversed(range(n)):
            res[i] += (balls + moves)
            moves += balls
            balls += (ord(boxes[i]) - ord('0'))
        
        return res