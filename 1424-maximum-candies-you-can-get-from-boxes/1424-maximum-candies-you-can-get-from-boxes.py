class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:

        seen = set()
        can_look = set()

        def dfs(box):
            if box in seen:
                return 0

            if status[box] == 0:
                can_look.add(box)
                return 0

            seen.add(box)
            total = candies[box]

            for next_box in containedBoxes[box]:
                total += dfs(next_box)

            for next_box in keys[box]:
                status[next_box] = 1
                if next_box in can_look:
                    total += dfs(next_box)

            return total


        

        return sum([dfs(box) for box in initialBoxes])
                
        