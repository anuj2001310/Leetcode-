class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        vector<int> map(101, 0);

        vector<int> ans;
        for (int i = 0; i < n; i++)
            map[bulbs[i]]++;

        for (int i = 0; i < 101; i++) {
            if ((map[i] & 1) && (map[i] > 0))
                ans.push_back(i);
        }
        
        return ans;
    }
};