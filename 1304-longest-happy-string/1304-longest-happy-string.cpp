class Solution {
public:
    pair<int, int> fun(int a, int b, int c) {
        int k1 = max(max(a, b), c);
        int k2;
        if (k1 == a)
            k2 = max(b, c);
        if (k1 == b)
            k2 = max(a, c);
        if (k1 == c)
            k2 = max(a, b);

        return {k1, k2};
    }

    string longestDiverseString(int a, int b, int c) {
        string res = "";
        int curr = 0;

        while ((a + b + c) > 0) {
            //cout << a << " " << b << " " << c << "\n";
            //cout << res << " " << curr << "\n";
            pair<int, int> p = fun(a, b, c);
            if (p.first == a) {
                if (res.size() >= 2) {
                    if (res[curr - 2] == 'a' && res[curr - 1] == 'a') {
                        if (p.second == 0)
                            return res;
                        if (p.second == b) {
                            res = res + "b";
                            b--;
                        } else {
                            res = res + "c";
                            c--;
                        }
                    } else {
                        res = res + "a";
                        a--;
                    }
                } else {
                    res = res + "a";
                    a--;
                }
                curr++;
            } else if (p.first == b) {
                if (res.size() >= 2) {
                    if (res[curr - 2] == 'b' && res[curr - 1] == 'b') {
                        if (p.second == 0)
                            return res;
                        if (p.second == a) {
                            res = res + "a";
                            a--;
                        } else {
                            res = res + "c";
                            c--;
                        }
                    } else {
                        res = res + "b";
                        b--;
                    }
                } else {
                    res = res + "b";
                    b--;
                }
                curr++;
            } else {
                if (res.size() >= 2) {
                    if (res[curr - 2] == 'c' && res[curr - 1] == 'c') {
                        if (p.second == 0)
                            return res;
                        if (p.second == b) {
                            res = res + "b";
                            b--;
                        } else {
                            res = res + "a";
                            a--;
                        }
                    } else {
                        res = res + "c";
                        c--;
                    }
                } else {
                    res = res + "c";
                    c--;
                }
                curr++;
            }
        }

        return res;
    }
};