class Solution {
    public int mirrorFrequency(String s) {
        int n = s.length();
        var digits = new int[10];
        var chars = new int[26];

        for (char ch : s.toCharArray()) {
            if (ch >= '0' && ch <= '9')
                digits[ch - '0']++;
            else
                chars[ch - 'a']++;
        }

        int sum = 0;
        for (int i = 0; i < (26 >> 1); ++i) {
            int fc = chars[i];
            int fm = chars[25 - i];

            sum += Math.abs(fc - fm);
        }

        for (int j = 0; j < (10 >> 1); j++) {
            int fc = digits[j];
            int fm = digits[9 - j];

            sum += Math.abs(fc - fm);
        }

        return sum;
    }
}