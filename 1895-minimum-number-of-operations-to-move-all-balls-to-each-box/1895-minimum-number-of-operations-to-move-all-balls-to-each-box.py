class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        prefix_right = [0 for _ in range(n)]
        prefix_left = [0 for _ in range(n)]

        #Scan from left --> right
        for i in range(n):
            temp = 0
            for j in range(i + 1, n):
                if boxes[j] == '1':
                    temp += abs(i - j)
            
            prefix_right[i] = temp
        
        #Scan from left <-- right
        for i in range(n - 1, -1, -1):
            temp = 0
            for j in range(i - 1, -1, -1):
                if boxes[j] == '1':
                    temp += abs(i - j)

            prefix_left[i] = temp

        #print(prefix_right)
        #print(prefix_left)
        
        #Add both the arrays 
        return [prefix_left[i] + prefix_right[i] for i in range(n)]
