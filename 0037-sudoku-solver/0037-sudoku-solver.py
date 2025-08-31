class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        for r in range(9):
            for c in range(9):
                if board[r][c] != '.':
                    rows[r].add(board[r][c])
                    cols[c].add(board[r][c])
                    box_id = r//3  * 3 + c//3 
                    boxes[box_id].add(board[r][c])
        
        def select_candidates( r, c):
            box_id = (r // 3) * 3 + (c // 3)
            candidates = set()
            for num in map(str, range(1, 10)):  # '1' to '9'
                if num not in rows[r] and num not in cols[c] and num not in boxes[box_id]:
                    candidates.add(num)
            return candidates

        def find_best_cell():
            min_candidates = 9
            best_cell = None
            best_candidates = set()
            for r in range(9):
                for c in range(9):
                    if board[r][c] == '.':
                        cell_candidates = select_candidates(r, c)
                        if len(cell_candidates) < min_candidates:
                            min_candidates = len(cell_candidates)
                            best_cell = (r, c)
                            best_candidates = cell_candidates
            return best_cell, best_candidates

        def backtrack():
            best_cell, candidates = find_best_cell()
            if not best_cell:
                # every cell is filled, sudoku is correct
                return True
            r,c = best_cell
            for can in candidates:
                #place num
                board[r][c] = can
                # add to the checking sets
                rows[r].add(can)
                cols[c].add(can)
                box_id = r//3  * 3 + c//3 
                boxes[box_id].add(can)
            
                if backtrack():
                    return True
                # undo 
                board[r][c] = '.'  
                rows[r].remove(can)
                cols[c].remove(can)
                boxes[box_id].remove(can) 

            return False      

        backtrack()