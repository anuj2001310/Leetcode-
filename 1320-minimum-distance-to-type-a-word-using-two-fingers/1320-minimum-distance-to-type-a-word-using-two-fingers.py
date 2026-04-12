class Solution(object):
    def minimumDistance(self, word):
        pos = [(i // 6, i % 6) for i in range(26)]

        dist = [[0] * 26 for _ in range(26)]
        for i in range(26):
            for j in range(26):
                dist[i][j] = abs(pos[i][0] - pos[j][0]) + abs(pos[i][1] - pos[j][1])

        w = [ord(c) - 65 for c in word]
        n = len(w)

        total = 0
        for i in range(1, n):
            total += dist[w[i - 1]][w[i]]

        dp = [0] * 27

        for i in range(n - 1):
            ndp = [0] * 27
            move = dist[w[i]][w[i + 1]]
            for j in range(27):
                val = dp[j]
                if val > ndp[j]:
                    ndp[j] = val
                save = move if j == 26 else move - dist[j][w[i + 1]]
                if val + save > ndp[w[i]]:
                    ndp[w[i]] = val + save
            dp = ndp

        return total - max(dp)
