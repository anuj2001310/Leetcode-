class Solution:
    def mirrorFrequency(self, s: str) -> int:
        chars = [0] * 26
        digits = [0] * 10
        for ch in s:
            if ch >= "0" and ch <= "9":
                digits[ord(ch) - 48] += 1
            else:
                chars[ord(ch) - 97] += 1

        Sum = 0
        for i in range((26 >> 1)):
            fc, fm = chars[i], chars[25 - i]
            Sum += abs(fc - fm)

        for i in range((10 >> 1)):
            fc, fm = digits[i], digits[9 - i]
            Sum += abs(fc - fm)

        return Sum
