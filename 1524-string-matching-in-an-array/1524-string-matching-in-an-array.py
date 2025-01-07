class Solution(object):
    def stringMatching(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        n = len(words)
        res = set()

        for i in range(n):
            for j in range(n):
                if i != j:
                    if words[j] in words[i]:
                        res.add(words[j])
        return list(res)