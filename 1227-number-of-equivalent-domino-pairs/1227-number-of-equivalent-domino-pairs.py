class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        hash = [0] * 100
        cnt = 0
        for d in dominoes:
            u, v = d[0], d[1]
            num = v * 10 + u if u > v else u * 10 + v
            cnt += hash[num]
            hash[num] += 1
        
        return cnt