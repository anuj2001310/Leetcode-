class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        hash = [False] * 10001
        for num in banned:
            hash[num] = True
        
        sm, cnt = 0, 0
        for i in range(1, n + 1):
            if not hash[i]:
                sm += i
                if sm <= maxSum:
                    cnt += 1
                else:
                    return cnt
            else:
                continue
        
        return cnt