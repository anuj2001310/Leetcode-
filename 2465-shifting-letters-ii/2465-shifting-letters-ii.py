class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        prefix = [0] * (n + 1)

        for shift in shifts:
            st, ed, dr = shift
            prefix[st] += (2 * dr - 1)
            if ed + 1 < n:
                prefix[ed + 1] -= (2 * dr - 1)

        sb = []
        currShift = 0

        for i in range(n):
            currShift = (currShift + prefix[i]) % 26
            ch = chr((ord(s[i]) - ord('a') + currShift + 26) % 26 + ord('a'))
            sb.append(ch)

        return ''.join(sb)