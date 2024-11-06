class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def value(s):
            val = 0
            for ch in s:
                val = val * 10 + (ord(ch) - ord("a"))
            return val

        return value(firstWord) + value(secondWord) == value(targetWord)
