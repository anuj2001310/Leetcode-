class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        n = len(board)
        m = len(board[0])
        vis = [[False for _ in range (m)] for _ in range(n)]
        q = deque()
        for i in range(n):
            for j in range(m):
                if i == 0 or i == n - 1 or j == 0 or j == m - 1:
                    if board[i][j] == 'O':
                        vis[i][j] = True
                        q.append([i, j])
        
        while q:
            top = q.popleft()
            r = top[0]
            c = top[1]
            for i in range(len(dirs)):
                nr = r + dirs[i][0]
                nc = c + dirs[i][1]
                if 0 <= nr < n and 0 <= nc < m and board[nr][nc] == 'O' and not vis[nr][nc]:
                    vis[nr][nc] = True
                    q.append([nr, nc])
        
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O' and not vis[i][j]:
                    board[i][j] = 'X'