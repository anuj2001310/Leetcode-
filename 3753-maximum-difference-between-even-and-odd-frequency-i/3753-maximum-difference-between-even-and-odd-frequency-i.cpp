class Solution {
public:
    int maxDifference(string s) {
        vector<int> arr(26, 0);
        for (int i = 0; s[i]; i++) {
            arr[s[i] - 'a']++;
        }
        int max = INT_MIN, min = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (arr[i] and (arr[i] & 1))
                max = fmax(max, arr[i]);
            if (arr[i] and (arr[i] & 1) == 0)
                min = fmin(min, arr[i]);
        }
        return max - min;
    }
};