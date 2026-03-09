class Solution {
public:
    int countOddLetters(int n) {
        vector<string> arr = {"zero", "one", "two",   "three", "four",
                              "five", "six", "seven", "eight", "nine"};
        vector<int> freq(26, 0);
        for (; n; n /= 10) {
            int r = n % 10;
            for (auto& ch : arr[r])
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
};