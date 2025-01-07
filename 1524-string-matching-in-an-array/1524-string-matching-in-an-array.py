class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res = set()
        n = len(words)

        for i in range(n):
            for j in range(n):
                if i != j:
                    if words[j] in words[i]:
                        res.add(words[j])
        return list(res)