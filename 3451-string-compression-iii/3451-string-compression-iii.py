class Solution:
    def compressedString(self, word: str) -> str:
        comp = ""  
        i = 0  

        while i < len(word):
            count = 1  
            current_char = word[i]  

            
            while i + 1 < len(word) and word[i + 1] == current_char and count < 9:
                count += 1
                i += 1

            comp += str(count) + current_char
            i += 1

        return comp