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
public:
    LL maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        LL ans = 0;
        Rep(i, n - 2) {
            FOR(j, i + 1, n - 1) {
                FOR(k, j + 1, n) {
                    ans = fmax(ans, (LL)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return ans;
    }
};