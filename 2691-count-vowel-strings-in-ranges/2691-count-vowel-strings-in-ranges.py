class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        prefix_arr = [0]
        prefix_sum = 0
        st = "aeiou"
        for i in range(len(words)):
            word = words[i]
            if word[0] in st and word[-1] in st:
                prefix_sum += 1
            prefix_arr.append(prefix_sum)
        
        res = []
        for l, r in queries:
            res.append(prefix_arr[r + 1] - prefix_arr[l])

        return res