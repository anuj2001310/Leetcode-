class Solution {
public:
    bool isCircularSentence(string sentence) {
        /*
        vector<string> help;
        string temp = "";
        for (int i = 0; i < sentence.length(); ++i) {
            if (sentence[i] == ' ') {
                help.push_back(temp);
                temp = "";
            } else
                temp += sentence[i];
        }
        help.push_back(temp);

        for (auto& str : help)
            cout << str << " -> ";
        */
        int n = sentence.length();
        if (sentence[0] != sentence[n - 1])
            return false;
        for (int i = 1; i <= n - 1; ++i) {
            if (sentence[i] == ' ')
                if (sentence[i - 1] != sentence[i + 1])
                    return false;
        }
        return true;
    }
};