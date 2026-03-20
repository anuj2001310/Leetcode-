class Solution:
    def equalFrequency(self, word: str) -> bool:

        freq = sorted(list(Counter(word).values()), reverse = True)
        if len(set(freq)) > 2: return False

        # check if decrementing the largest frequency allows to equalize char frequencies
        freq[0] -= 1
        if len(set(freq)) == 1:
            return True
        freq[0] += 1

        # check if decrementing the smallest frequency either gives frequency 0 with all other
        # frequencies equal or allows to equalize char frequencies
        freq[-1] -= 1
        if freq[-1] == 0:
            freq.pop()
        if len(set(freq)) == 1:
            return True
        return False
        #    end equalFrequency(...)