class Solution {
public:
    char kthCharacter(int k) {
        string start = "a";
        while (start.length() < k) {
            string temp = "";
            for (auto& ch : start) {
                char next = (ch == 'z') ? 'a' : (ch + 1);
                temp.push_back(next);
            }
            start += temp;
        }
        return start[k - 1];
    }
};