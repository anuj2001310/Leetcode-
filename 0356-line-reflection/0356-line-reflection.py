class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        min_x, max_x = float("+inf"), float("-inf")

        for x, y in points:
            min_x = min(min_x, x)
            max_x = max(max_x, x)

        mid_point = (min_x + max_x) / 2

        for x, y in points:
            gr_x = 2 * mid_point - x
            if [gr_x, y] not in points:
                return False

        return True
