class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        #print(words)
        def count_vowel(res: str) -> int:
            cnt = 0
            vowels = 'aeiou'
            for ch in res:
                if ch in vowels:
                    cnt += 1
            
            return cnt
        

        v = count_vowel(words[0])
        for i in range(1, len(words)):
            if count_vowel(words[i]) == v:
                words[i] = words[i][::-1]
        
        return " ".join(words)