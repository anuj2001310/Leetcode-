class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        pg = p = [-1] * n
        p[0] = nums[0]
        for i in range(1, n):
            p[i] = max(p[i - 1], nums[i])

        for i in range(1, n):
            pg[i] = math.gcd(p[i], nums[i])

        pg.sort()
        i, j = 0, n - 1
        s = 0

        while i < j:
            s += math.gcd(pg[i], pg[j])
            i += 1
            j -= 1

        return s
