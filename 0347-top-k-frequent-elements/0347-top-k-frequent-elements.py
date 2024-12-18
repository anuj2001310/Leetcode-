class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freqs = {}
        for num in nums:
            freqs[num] = freqs.get(num, 0) - 1
        
        freqs = [(val, key) for key, val in freqs.items()]
        heapq.heapify(freqs)

        i = 0
        out = []
        while i < k:
            out.append(heapq.heappop(freqs)[1])
            i += 1
        return out 