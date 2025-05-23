class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n = len(arr)
        minheap = []
        heapq.heapify(minheap)

        for i in range(n):
            num = abs (arr[i] - x)
            heapq.heappush(minheap, (num, arr[i]))
        
        ans = []
        while k and minheap:
            val = heapq.heappop(minheap)
            ans.append(val[1])
            k -= 1
        
        ans.sort()
        return ans