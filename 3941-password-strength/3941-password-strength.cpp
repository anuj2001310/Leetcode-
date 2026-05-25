class Solution {
public:
    int passwordStrength(string password) {
        int n = password.length();
        int cnt = 0;
        unordered_set<char> vis;
        string symbols = "!@#$";

        for (int i = 0; i < n; i++) {
            if (vis.find(password[i]) != vis.end())
                continue;
            else if (islower(password[i]))
                cnt += 1;
            else if (isupper(password[i]))
                cnt += 2;
            else if (isdigit(password[i]))
                cnt += 3;
            else if (symbols.find(password[i]) != string::npos)
                cnt += 5;
            
            vis.insert(password[i]);
        }
        return cnt;
    }
};