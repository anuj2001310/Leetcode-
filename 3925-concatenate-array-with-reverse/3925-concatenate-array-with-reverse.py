class Solution:
    def concatWithReverse(self, arr: list[int]) -> list[int]:
        return arr + arr[:: -1]