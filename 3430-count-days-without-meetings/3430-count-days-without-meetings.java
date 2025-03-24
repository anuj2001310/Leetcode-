class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> (a[0] - b[0]));
        int cntDays = meetings[0][0] - 1, end = meetings[0][1];

        for (int indx = 1; indx < meetings.length; indx++) {
            int start = meetings[indx][0];
            if (start > end) {
                cntDays += (start - end - 1);
            }
            end = Math.max(end, meetings[indx][1]);
        }
        if (end < days)
            return days - end + cntDays;
        return cntDays;
    }
}