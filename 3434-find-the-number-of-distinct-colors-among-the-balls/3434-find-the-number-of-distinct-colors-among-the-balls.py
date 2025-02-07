class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        ball_col = {}
        col_cnt = {}
        res = []

        for (ball, color) in queries:
            if ball in ball_col:
                prev = ball_col[ball]
                col_cnt[prev] -= 1
                if col_cnt[prev] == 0:
                    del col_cnt[prev]
            
            ball_col[ball] = color
            col_cnt[color] = col_cnt.get(color, 0) + 1

            res.append(len(col_cnt))
        
        return res