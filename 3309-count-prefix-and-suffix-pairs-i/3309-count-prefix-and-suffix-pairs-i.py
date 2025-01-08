class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        cnt = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if words[j].find(words[i], 0, len(words[i])) == 0  and words[j][::-1].find(words[i][::-1], 0, len(words[i])) == 0:
                    cnt += 1
        return cnt  