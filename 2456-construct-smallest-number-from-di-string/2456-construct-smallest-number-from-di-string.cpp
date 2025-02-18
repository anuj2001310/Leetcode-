class Solution {
public:
    string result = "";
    string pattern;
    vector<bool> visited;
    string tempNumber = "";

    void dfs(int index) {
        if (result != "")
            return;

        if (index == pattern.size() + 1) {
            result = tempNumber;
            return;
        }

        for (int i = 1; i < 10; ++i) {
            if (!visited[i]) {
                if (index > 0) {
                    if (!tempNumber.empty()) {
                        if (pattern[index - 1] == 'I' &&
                            tempNumber.back() - '0' >= i)
                            continue;
                        if (pattern[index - 1] == 'D' &&
                            tempNumber.back() - '0' <= i)
                            continue;
                    }
                }
                visited[i] = true;
                tempNumber += to_string(i);
                dfs(index + 1);
                tempNumber.pop_back();
                visited[i] = false;
            }
        }
    }

    string smallestNumber(string pattern) {
        this->pattern = pattern;
        visited.assign(10, false);
        result = "";
        tempNumber = "";
        dfs(0);
        return result;
    }
};