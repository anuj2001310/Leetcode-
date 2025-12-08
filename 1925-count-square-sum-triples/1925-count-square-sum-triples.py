class Solution:
    def countTriples(self, n: int) -> int:
        squares = set([i * i for i in range(1, n + 1)])
        cnt = 0

        for a in range(1, n + 1):
            for b in range(a + 1, n + 1):
                if a * a + b * b in squares:
                    cnt += 2
            
        #return answer
        return cnt