class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [[False] * 9 for _ in range(9)]
        cols = [[False] * 9 for _ in range(9)]
        boxs = [[False] * 9 for _ in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    num = ord(board[i][j]) - ord('1')
                    boxIndex = (i // 3) * 3 + (j // 3)
                    if rows[i][num] or cols[j][num] or boxs[boxIndex][num]:
                        return False
                    rows[i][num] = cols[j][num] = boxs[boxIndex][num] = True
                    
        
        return True