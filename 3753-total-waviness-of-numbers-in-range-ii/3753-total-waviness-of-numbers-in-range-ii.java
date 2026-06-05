class Solution {
    private int getDir(int a, int b) {
        if (a < b)
            return 0;
        if (a == b)
            return 1;
        return 2;
    }

    private boolean matchDir(int dir1, int dir2) {
        return (dir1 == 0 && dir2 == 2) || (dir1 == 2 && dir2 == 0);
    }

    private int index(int pos, int tie, int lastDir, int lastDigit) {
        return ((pos * 2 + tie) * 3 + lastDir) * 10 + lastDigit;
    }

    private long helper(long num) {
        if (num <= 0)
            return 0;
        char[] chars = Long.toString(num).toCharArray();
        int m = chars.length;
        int[] digits = new int[m];
        for (int i = 0; i < m; i++) {
            digits[i] = chars[i] - '0';
        }

        long[] totalWaviness = new long[m * 2 * 3 * 10];
        long[] totalWays = new long[m * 2 * 3 * 10];
        for (int firstPos = 0; firstPos < m; firstPos++) {
            int maxFirstDigit = firstPos == 0 ? digits[0] : 9;
            for (int firstDigit = 1; firstDigit <= maxFirstDigit; firstDigit++) {
                int tie = firstPos == 0 ? (firstDigit < digits[0] ? 1 : 0) : 1;
                int lastDir = 1;
                totalWays[index(firstPos, tie, lastDir, firstDigit)]++;
            }
        }
        for (int pos = 0; pos + 1 < m; pos++) {
            for (int tie = 0; tie < 2; tie++) {
                for (int lastDir = 0; lastDir < 3; lastDir++) {
                    for (int lastDigit = 0; lastDigit < 10; lastDigit++) {
                        int idx = index(pos, tie, lastDir, lastDigit);
                        if (totalWays[idx] == 0)
                            continue;

                        int maxNextDigit = tie == 1 ? 9 : digits[pos + 1];
                        for (int nextDigit = 0; nextDigit <= maxNextDigit; nextDigit++) {
                            int newTie = (tie == 1 || nextDigit < digits[pos + 1]) ? 1 : 0;
                            int newDir = getDir(lastDigit, nextDigit);
                            int newIdx = index(pos + 1, newTie, newDir, nextDigit);

                            totalWaviness[newIdx] += totalWaviness[idx]
                                    + totalWays[idx] * (matchDir(lastDir, newDir) ? 1 : 0);
                            totalWays[newIdx] += totalWays[idx];
                        }
                    }
                }
            }
        }
        long ans = 0;
        for (int tie = 0; tie < 2; tie++) {
            for (int lastDir = 0; lastDir < 3; lastDir++) {
                for (int lastDigit = 0; lastDigit < 10; lastDigit++) {
                    ans += totalWaviness[index(m - 1, tie, lastDir, lastDigit)];
                }
            }
        }
        return ans;
    }

    public long totalWaviness(long num1, long num2) {
        return helper(num2) - helper(num1 - 1);

    }
}