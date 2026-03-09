public class Solution {
    public int CountOddLetters(int n) {
        string[] arr = {"zero", "one", "two", "three", "four",
                "five", "six", "seven", "eight", "nine" };

        var freq = new int[26];
        for (; n > 0; n /= 10) {
            int r = n % 10;
            foreach (var ch in arr[r])
                freq[ch - 'a']++;
        }
        
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;
            cnt += ((freq[i] & 1) > 0 ? 1 : 0);
        }
        return cnt;
    }
}