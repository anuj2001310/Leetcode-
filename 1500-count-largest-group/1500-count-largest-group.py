class Solution:
    def countLargestGroup(self, n: int) -> int:
        sums = [0] * 37
        for i in range(1, n + 1):
            sums[sum(int(x) for x in str(i))] += 1
        m, cnt = 0, 0
        for s in sums:
            if s > m:
                m = s
                cnt = 1
            elif s == m:
                cnt += 1
        
        return cnt