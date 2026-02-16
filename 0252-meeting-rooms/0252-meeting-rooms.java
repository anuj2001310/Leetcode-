class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        Stack<int[]> stk = new Stack<>();


        for (int i = 0; i < n; ++i) {
            if (!stk.isEmpty() && stk.peek()[1] > intervals[i][0])
                return false;
            stk.push(new int[]{intervals[i][0], intervals[i][1]});
        }
        return true;
    }
}