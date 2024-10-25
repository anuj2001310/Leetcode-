class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> ans;
        ans.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string currfolder = folder[i];
            string lastfolder = ans.back();
            lastfolder += '/';

            if (currfolder.find(lastfolder) != 0)
                ans.push_back(currfolder);
            
        }
        return ans;
    }
};