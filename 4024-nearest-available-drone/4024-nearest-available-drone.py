class Solution:
    def nearestDrone(self, drones: list[list[int]], target: list[int]) -> int:
        mindis, ans = inf, -1

        for idx, (x, y, r) in enumerate(drones):
            dis = abs(x - target[0]) + abs(y - target[1])
            if r >= dis and dis < mindis:
                mindis = dis
                ans = idx
        
        return ans