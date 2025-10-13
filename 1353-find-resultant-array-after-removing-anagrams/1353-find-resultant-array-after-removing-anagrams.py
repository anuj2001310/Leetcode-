class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        def anagram(s : str, r : str) -> bool:
            if len(s) != len(r):
                return False
            
            freq = [0 for _ in range(26)]
            for i in range(len(s)):
                freq[ord(s[i]) - ord('a')] += 1
                freq[ord(r[i]) - ord('a')] -= 1
            
            for i in range(26):
                if freq[i] != 0:
                    return False
            
            return True

        n = len(words)
        res = [words[0]]
        for i in range(1, n):
            if anagram(words[i], words[i - 1]):
                continue
            res.append(words[i])
        
        return res
        
