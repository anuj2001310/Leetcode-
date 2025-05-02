class Solution(object):
    def countCoveredBuildings(self, n, buildings):
        """
        :type n: int
        :type buildings: List[List[int]]
        :rtype: int
        """
        x_min, y_min = [float('inf')] * (n + 1), [float('inf')] * (n + 1)
        x_max, y_max = [float('-inf')] * (n + 1), [float('-inf')] * (n + 1)
        for building in buildings:
            x, y = building[0], building[1]
            x_min[x] = min(x_min[x], y)
            x_max[x] = max(x_max[x], y)
            y_min[y] = min(y_min[y], x)
            y_max[y] = max(y_max[y], x)

        return sum(1 if building[1] > x_min[building[0]] and building[1] < x_max[building[0]] and building[0] > y_min[building[1]] and building[0] < y_max[building[1]] else 0 for building in buildings)