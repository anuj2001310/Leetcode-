class Solution:
    def minimumBoxes(self, apple: List[int], c: List[int]) -> int:
        x = sum(apple)
        v = 0
        c.sort(reverse = True)
        n = len(c)
        for i in range(n):
            v += c[i]
            if v >= x:
                return i + 1
        return -1
