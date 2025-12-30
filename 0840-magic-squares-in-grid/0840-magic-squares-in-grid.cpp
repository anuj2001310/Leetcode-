// Start Of Anuj Bhati aka Edwards310's Template...
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<char, bool> pcb;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
typedef pair<string, string> pss;
typedef pair<char, char> pcc;
typedef pair<int, vi> pivi;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vd> vvd;
typedef vector<vs> vvs;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef vector<pcb> vpcb;
typedef vector<psi> vpsi;
typedef vector<pci> vpci;
typedef vector<pss> vpss;
typedef vector<LL> vll;
typedef vector<vll> vvll;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

#define FOR(a, b, c) for (int a = b; a < c; a++)
#define FOR1(a, b, c) for (int a = b; a <= c; ++a)
#define Rep(i, n) FOR(i, 0, n)
#define Rep1(i, n) FOR1(i, 1, n)
#define RepA(ele, nums) for (auto& ele : nums)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define mxe(v) max_element(ALL(v))
#define mie(v) min_element(ALL(v))
#define bitsDedo(n) __builtin_popcount(n)
#define umii unordered_map<int, int>
#define umci unordered_map<char, int>
#define umcc unordered_map<char, char>
#define umsi unordered_map<string, int>
#define umipii unordered_map<int, pii>
#define umpiii unordered_map<pii, int>
#define umivi unordered_map<int, vi>
#define umili unordered_map<int, list<int>>
#define umss unordered)map<string, string>
#define usi unordered_set<int>
#define usc unordered_set<char>
#define sti stack<int>
#define stc stack<char>
#define sts stack<string>
#define mii map<int, int>
#define mpiii map<pii, int>
#define mipii map<int, pii>
#define mivi map<int, vi>
#define mllll map<LL, LL>
#define mci map<char, int>
#define mcc map<char, char>
#define mis map<int, string>
#define msi map<string, int>
#define mss map<string, string>
#define qi queue<int>
template <class Y> void swap(Y& x, Y& y) {
    x = x + y;
    y = x - y;
    x = x - y;
}
template <typename X, typename Y> void add(X& x, Y& y) { return x + y; }
template <class T> class Stack {
public:
    int top = -1;
    Stack() {}
};
// end of Anuj Bhati's aka Edwards310's Template
class Solution {
    inline bool isMagic(char i, char j, char a, char b, char c, char d,
                        vvi& grid) {
        return (a + grid[i - 1][j] + b == 15) &&
               (a + grid[i][j - 1] + c == 15) &&
               (b + grid[i][j + 1] + d == 15) && (c + grid[i + 1][j] + d == 15);
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if (r < 3 || c < 3)
            return 0;

        int cnt = 0;
        for (char i = 1; i < r - 1; i++) {
            for (char j = 1; j < c - 1; j++) {
                if (grid[i][j] != 5)
                    continue;
                char a = grid[i - 1][j - 1], b = grid[i - 1][j + 1],
                     c = grid[i + 1][j - 1], d = grid[i + 1][j + 1];
                uint16_t once = ((1 << 2) | (1 << 4) | (1 << 6) | (1 << 8)) ^
                                ((1 << a) | (1 << b) | (1 << c) | (1 << d));
                // check diagonals & center, numbers in corner are even
                if (once == 0 && (a & 1) == 0 && a + d == 10 && (b & 1) == 0 &&
                    b + c == 10)
                    cnt += isMagic(i, j, a, b, c, d, grid);
            }
        }
        return cnt;
    }
};