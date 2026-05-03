class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False

        st = s + s
        if goal in st:
            return True
            
        return False