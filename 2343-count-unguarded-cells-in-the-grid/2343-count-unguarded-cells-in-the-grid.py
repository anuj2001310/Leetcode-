class Solution(object):
    def countUnguarded(self, m, n, guards, walls):
        """
        :type m: int
        :type n: int
        :type guards: List[List[int]]
        :type walls: List[List[int]]
        :rtype: int
        """
        vis = [[0 for _ in range(n)] for _ in range(m)]
        #print(res)
        #Mark present guards by 2
        for arr in guards:
            vis[arr[0]][arr[1]] = 2
        
        #Mark present walls by 3
        for arr in walls:
            vis[arr[0]][arr[1]] = 3
        
        for i in range(len(guards)):
            r = guards[i][0]
            c = guards[i][1]
            left, right = c - 1, c + 1
            up, down = r - 1, r + 1
            #Left-Movement
            while left >= 0:
                if vis[r][left] == 3 or vis[r][left] == 2:
                    break
                vis[r][left] = 1
                left -= 1
            
            #Right-Movement
            while right < n:
                if vis[r][right] == 3 or vis[r][right] == 2:
                    break
                vis[r][right] = 1
                right += 1
            
            #Up-Movement
            while up >= 0:
                if vis[up][c] == 3 or vis[up][c] == 2:
                    break
                vis[up][c] = 1
                up -= 1
            
            #Down-Movement
            while down < m:
                if vis[down][c] == 3 or vis[down][c] == 2:
                    break
                vis[down][c] = 1
                down += 1
            
        return sum(1 for i in range(m) for j in range(n) if vis[i][j] == 0)