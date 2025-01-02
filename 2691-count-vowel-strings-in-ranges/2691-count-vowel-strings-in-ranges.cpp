class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> prefixSum(words.size() + 1, 0);

        for (int i = 0; i < words.size(); i++) {
            if (vowels.count(words[i][0]) && vowels.count(words[i].back()))
                prefixSum[i + 1] = prefixSum[i] + 1;
            else
                prefixSum[i + 1] = prefixSum[i];
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) 
            ans.push_back(prefixSum[queries[i][1] + 1] - prefixSum[queries[i][0]]);
        
        return ans;
    }
};