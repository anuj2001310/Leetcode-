class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        n = len(intervals)
        intervals.sort(key=lambda x: x[0])

        stk = []
        for i in range(n):
            if stk and stk[-1][1] > intervals[i][0]:
                return False
            stk.append([intervals[i][0], intervals[i][1]])
        return True