class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        cnt = 0
        word = text.split()
        for w in word:
            f = True
            for ch in brokenLetters:
                if ch in w:
                    f = False
                    break
            if f:
                cnt += 1

        return cnt