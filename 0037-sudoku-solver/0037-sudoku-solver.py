class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9

        for r in range(9):
            for c in range(9):
                if board[r][c] != '.':
                    num = int(board[r][c])
                    bit = 1 << (num - 1)
                    box_idx = (r // 3) * 3 + (c // 3)
                    rows[r] |= bit
                    cols[c] |= bit
                    boxes[box_idx] |= bit

        def backtrack(r, c):
            if r == 9:
                return True
            
            next_r = r + (c + 1) // 9
            next_c = (c + 1) % 9

            if board[r][c] != '.':
                return backtrack(next_r, next_c)

            box_idx = (r // 3) * 3 + (c // 3)
            for i in range(1, 10):
                bit = 1 << (i - 1)
                
                if not (rows[r] & bit or cols[c] & bit or boxes[box_idx] & bit):
                    num_str = str(i)
                    board[r][c] = num_str
                    rows[r] |= bit
                    cols[c] |= bit
                    boxes[box_idx] |= bit

                    if backtrack(next_r, next_c):
                        return True

                    board[r][c] = '.'
                    rows[r] ^= bit
                    cols[c] ^= bit
                    boxes[box_idx] ^= bit
            
            return False

        backtrack(0, 0)