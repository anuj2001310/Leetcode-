class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)
        map = collections.defaultdict(list)
        for i in range(n):
            map[nums[i]].append(i)

        ans = inf
        for k, v in map.items():
            if len(v) < 3:
                continue
            temp = 0
            for j in range(len(v) - 2):
                temp = abs(v[j] - v[j + 1]) + abs(v[j + 1] - v[j + 2]) + abs(v[j + 2] - v[j])
                ans = min(ans, temp)

        return -1 if ans == inf else ans 