class Solution {
    using pss = pair<string, string>;
private:
    bool check(string& str) {
        if (str.empty())
            return false;
        string ot = "@#$%^&*() -+=!:,~`<>?|{}[];'";
        for (auto& ch : str) {
            if (ot.find(ch) != string::npos)
                return false;
        }
        return true;
    }
    bool check2 (string& str) {
        vector<string> arr = {"electronics", "grocery", "pharmacy", "restaurant"};
        for (auto& a : arr) {
            if (a == str)
                return true;
        }
        return false;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        priority_queue<pss, vector<pss>, greater<pss>> pq;
        int n = code.size();
        for (int i = 0; i < n; i++) {
            string c = code[i];
            string b = businessLine[i];
            bool a = isActive[i];
            if (!check(c))
                continue;
            if (!check2(b))
                continue;
            if (a)
                pq.push({b, c});
        }
        vector<string> ans;
        while (!pq.empty()) {
            auto code = pq.top().second;
            pq.pop();
            ans.push_back(code);
        }

        return ans;
    }
};