class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long can = 0;
        for (int x : chalk)
            can += x;
        k %= can;
        for (int i = 0; i < chalk.length; i++) {
            if (chalk[i] > k)
                return i;
            k -= chalk[i];
        }
        return -1; // No use of this actually
    }
}