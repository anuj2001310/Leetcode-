class Solution {
    public double angleClock(int hour, int minutes) {
        hour = hour % 12;
        double hourAngle = 0.5 * ((hour * 60) + minutes);

        // in one minute the minute hand make an angle of 6 degree
        double minAngle = 6 * minutes;

        double angle1 = (double) Math.abs(hourAngle - minAngle);
        double angle2 = 360 - angle1;
        return Math.min(angle1, angle2);
    }
}