class Solution {
    public int countOddLetters(int n) {
        String[] arr = { "zero", "one", "two", "three", "four",
                "five", "six", "seven", "eight", "nine" };
        int[] freq = new int[26];
        for (; n > 0; n /= 10) {
            int r = n % 10;
            for (char ch : arr[r].toCharArray())
                freq[ch - 'a']++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;
            cnt += (freq[i] & 1);
        }
        return cnt;
    }
}