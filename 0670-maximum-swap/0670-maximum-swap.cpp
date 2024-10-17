class Solution {
public:
    int maximumSwap(int num) {
        string s_num = to_string(num);
        int n = s_num.length();
        for (int i = 0; i < n; i++) {
            char max_val = s_num[i];
            int max_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (max_val <= s_num[j]) {
                    max_val = s_num[j];
                    max_idx = j;
                }
            }
            if (max_val != s_num[i]) {
                swap(s_num[i], s_num[max_idx]);
                break;
            }
        }
        return stoi(s_num);
    }
};