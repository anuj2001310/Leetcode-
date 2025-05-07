class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        row = len(moveTime)
        col = len(moveTime[0])
        visited = [[False] * col for _ in range(col)]
        v = set()
        q = [(0, 0, 0)]
        heapq.heapify(q)
        direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        curr_time = 0
        while q:
            curr_time, x, y = heapq.heappop(q)
            if x == row - 1 and y == col - 1:
                return curr_time
            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 0 <= nx < row and 0 <= ny < col and not visited[nx][ny]:
                    visited[nx][ny] = True
                    if curr_time >= moveTime[nx][ny]:
                        heapq.heappush(q, (curr_time + 1, nx, ny))
                    else:
                        heapq.heappush(q, (moveTime[nx][ny] + 1, nx, ny))
                    v.add((nx, ny))
        return -1
