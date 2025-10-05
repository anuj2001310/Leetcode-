from collections import *
#import heapq

class Solution:
    def majorityFrequencyGroup(self, s: str) -> str:
        
        freq = [0] * 26
        for ch in s:
            freq[ord(ch) - ord('a')] += 1

        freq_map = defaultdict(list)
        for i in range(26):
            if freq[i] > 0:
                freq_map[freq[i]].append(chr(i + ord('a')))

        heap = []
        for f, chars in freq_map.items():
            heapq.heappush(heap, (-len(chars), -f, chars))

        _, _, top_chars = heapq.heappop(heap)

        return ''.join(top_chars)
