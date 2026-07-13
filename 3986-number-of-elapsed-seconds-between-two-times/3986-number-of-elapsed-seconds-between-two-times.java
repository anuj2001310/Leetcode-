class Solution {
    private int seconds (String str) {
        int h = 10 * (str.charAt(0) - '0') + (str.charAt(1) - '0');
        int m = 10 * (str.charAt(3) - '0') + (str.charAt(4) - '0');
        int s = 10 * (str.charAt(6) - '0') + (str.charAt(7) - '0');

        return 3600 * h + 60 * m + s;
    }
    public int secondsBetweenTimes(String st, String et) {
        return seconds(et) - seconds(st);
    }
}