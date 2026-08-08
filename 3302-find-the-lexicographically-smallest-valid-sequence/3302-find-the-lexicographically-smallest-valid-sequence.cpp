class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int N = word1.length();
        int M = word2.length();
        
        // lastOccur[j] stores the largest index in word1 
        // that can match word2[j] in a valid suffix match
        vector<int> lastOccur(M, -1);
        int j = M - 1;
        for (int i = N - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                lastOccur[j] = i;
                j--;
            }
        }
        
        bool changeUsed = false;
        vector<int> res;
        j = 0;
        
        // Greedily match word1 and word2 from left to right
        for (int i = 0; i < N && j < M; i++) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            } 
            else if (!changeUsed && (j == M - 1 || lastOccur[j + 1] > i)) {
                changeUsed = true;
                res.push_back(i);
                j++;
            }
        }
        
        if (res.size() == M) {
            return res;
        }
        
        return {};
    }
};