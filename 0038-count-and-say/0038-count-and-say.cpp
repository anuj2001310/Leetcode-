class Solution {
public:
    string countAndSay(int n) {
        string start = "1";
        while (n-- > 1) {
            vector<int> num;
            int cnt = 0, ele = -1;
            for (int i = 0; i < start.size(); i++) {
                if (ele == -1) {
                    ele = start[i] - '0';
                    cnt++;
                    continue;
                }
                if (ele != start[i] - '0') {
                    num.push_back(cnt);
                    num.push_back(ele);
                    ele = start[i] - '0', cnt = 1;
                } else
                    cnt++;
            }
            if (ele != -1) {
                num.push_back(cnt);
                num.push_back(ele);
            }
            start = "";
            for (int a : num) {
                start += (a + '0');
            }
        }
        return start;
    }
};