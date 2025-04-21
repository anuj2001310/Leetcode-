public class Solution {
    public int NumberOfArrays(int[] differences, int lower, int upper) {
        var cur = 0;
        var min = 0;
        var max = 0;
        foreach (var d in differences) {
            cur += d;
            min = (min < cur) ? min : cur;
            max = (max > cur) ? max : cur;

            if ((upper - max) - (lower - min) + 1 <= 0)
                return 0;
        }
        return (upper - lower) - (max - min) + 1;
    }
}