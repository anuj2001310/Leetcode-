class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split()
        cnt = 0
        for word in words:
            flag = True
            for ch in brokenLetters:
                if ch in word:
                    flag = False
                    break
            
            if flag:
                cnt += 1
        
        return cnt
                    