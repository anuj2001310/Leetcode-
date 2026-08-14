class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        freq = {}

        for word in words:
            freq[word] = freq.get(word, 0) + 1

        pq = list(freq.items())

        pq.sort(key=lambda x: (-x[1], x[0]))

        ans = []

        for i in range(k):
            ans.append(pq[i][0])

        return ans
            