class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        dick = collections.defaultdict(list)
        n = len(grid)

        for i in range(n):
            for j in range(n):
                diff = i - j
                dick[diff].append(grid[i][j])
        
        for k, arr in dick.items():
            if k >= 0:
                arr.sort()
            else:
                arr.sort(reverse = True)
        
        for i in range(n):
            for j in range(n):
                grid[i][j] = dick[i - j][-1]
                dick[i - j].pop()
        
        return grid