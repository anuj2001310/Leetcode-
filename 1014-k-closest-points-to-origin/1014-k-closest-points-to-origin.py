class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def dist(x : int, y : int) -> int:
            return x * x + y * y
        
        pq = []
        
        for point in points:
            x, y = point
            dis = dist(x, y)
            heapq.heappush(pq, (dis, point))
        
        ans = []
        for _ in range(k):
            _, point = heapq.heappop(pq)
            ans.append(point)
        
        return ans