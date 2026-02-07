class Solution:
    def countMonobit(self, n: int) -> int:
        return sum(1 for i in range(n + 1) if len(set(bin(i)[2: ])) == 1)