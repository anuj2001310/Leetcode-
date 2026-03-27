class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        k %= len(mat[0])
        if not k:
            return True
        for row in mat:
            s = "".join(chr(c + 97) for c in row)
            if s not in (s + s)[1:-1]:
                return False
        return True
