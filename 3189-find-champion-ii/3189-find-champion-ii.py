class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        inDeg = [0] * n
        for i in range(len(edges)):
            v = edges[i][1]
            inDeg[v] += 1
        
        cnt, ans = 0, -1
        for i in range(len(inDeg)):
            if inDeg[i] == 0:
                cnt += 1
                ans = i
        return ans if cnt == 1 else -1