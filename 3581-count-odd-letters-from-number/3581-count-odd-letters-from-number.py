class Solution:
    def countOddLetters(self, n: int) -> int:
        arr = [
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine",
        ]
        freq = [0 for _ in range(26)]

        while n:
            r = n % 10

            for ch in arr[r]:
                freq[ord(ch) - 97] += 1
                
            n //= 10

        return sum(1 for i in range(26) if freq[i] & 1)
