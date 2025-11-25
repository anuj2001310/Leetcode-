class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k == 1:
            return 1

        rem = 1
        length = 1
        seen = {1}
        # Use modular artithmetic
        while rem != 0:
            rem = (rem * 10 + 1) % k
            if rem in seen:
                return -1

            seen.add(rem)
            length += 1

        return length
