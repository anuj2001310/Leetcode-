class Solution {
private:
    int seconds(string str) {
        int h = stoi(str.substr(0, 2));
        int m = stoi(str.substr(3, 2));
        int s = stoi(str.substr(6, 2));

        return 3600 * h + 60 * m + s;
    }
public:
    int secondsBetweenTimes(string s, string e) {
        return seconds(e) - seconds(s);
    }
};