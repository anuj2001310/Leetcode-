class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        n = len(words)
        res = []

        for i in range(n):
            for j in range(n):
                if i != j:
                    if words[j] in words[i]:
                        res.append(words[j])
        
        return list(set(res))