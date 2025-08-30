class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n, m = len(board), len(board[0])
        rows = [[False] * n for _ in range(n)]
        cols = [[False] * m for _ in range(m)]
        boxes = [[False] * n for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if board[i][j] != '.':
                    num = ord(board[i][j]) - ord('1')
                    boxIndex = (i // 3) * 3 + (j // 3)
                    if rows[i][num] or cols[j][num] or boxes[boxIndex][num]:
                        return False
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = True
        return True