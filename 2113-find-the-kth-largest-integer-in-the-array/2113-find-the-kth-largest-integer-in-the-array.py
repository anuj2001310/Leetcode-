class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        maxHeap = [-int(st) for st in nums]
        heapq.heapify(maxHeap)

        while k > 1 and maxHeap:
            heapq.heappop(maxHeap)
            k -= 1

        return str(-maxHeap[0])
