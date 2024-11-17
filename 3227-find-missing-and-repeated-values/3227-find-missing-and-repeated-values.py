class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        row = len(grid)
        col = len(grid[0])
        list = [-1] * ((row * col) + 1) 
        for x in grid:
            for y in x:
                list[y] += 1
        ans = []
        for i in range(1, len(list) + 1):
            if list[i] == 1:
                ans.append(i)
                break
        
        for i in range(1, len(list) + 1):
            if list[i] == -1:
                ans.append(i)
                break
        return ans
