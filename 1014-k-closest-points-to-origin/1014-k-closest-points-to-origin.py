import heapq
class Solution(object):
    def kClosest(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        def distance(x, y):
            return x * x + y * y

        pq = []
        
        for point in points:
            x, y = point
            dis = distance(x, y)
            heapq.heappush(pq, (dis, point))
        
        ans = []
        for _ in range(k):
            _, point = heapq.heappop(pq)
            ans.append(point)
        
        return ans
