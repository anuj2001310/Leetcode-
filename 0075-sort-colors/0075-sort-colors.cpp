class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> help(3, 0);
        for (auto& x : nums)
            help[x]++;
        nums.clear();
        for (int i = 0; i < help.size(); i++) {
            int num = help[i];
            while (num--)
                nums.push_back(i);
        }
    }
};