class Solution:
    def numWaterBottles(self, b: int, e: int) -> int:
        return (b * e - 1) // (e - 1)