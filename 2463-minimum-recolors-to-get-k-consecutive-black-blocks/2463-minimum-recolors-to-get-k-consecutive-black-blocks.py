class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n = len(blocks)
        l, numWhites, numRecolors = 0, 0, float('inf')
        for r in range(n):
            if blocks[r] == 'W':
                numWhites += 1
            if r - l + 1 == k:
                numRecolors = min(numRecolors, numWhites)

                if blocks[l] == 'W':
                    numWhites -= 1
                l += 1
        
        return numRecolors