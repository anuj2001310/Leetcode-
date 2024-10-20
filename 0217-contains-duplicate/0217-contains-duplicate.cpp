// Start Of Anuj Bhati aka papaji310's Template...
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<char, bool> pcb;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vs> vvs;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef vector<LL> vll;
typedef vector<vll> vvll;
typedef pair<LL, LL> pll;
typedef pair<int, vi> pivi;
typedef pair<string, string> pss;
typedef pair<char, char> pcc;
typedef pair<char, int> pci;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

#define FOR(a, b, c) for (int a = b; a < c; a++)
#define FOR1(a, b, c) for (int a = b; a <= c; ++a)
#define Rep(i, n) FOR(i, 0, n)
#define Rep1(i, n) FOR1(i, 1, n)
#define Whl(i, n) while (i < n)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define mxe(v) max_element(ALL(v))
#define mie(v) min_element(ALL(v))
#define umii unordered_map<int, int>
#define umci unordered_map<char, int>
#define umcc unordered_map<char, char>
#define umsi unordered_map<string, int>
#define umipii unordered_map<int, pii>
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
#define msi map<string, int>
#define mss map<string, string>
template <class Y> void swap(Y& x, Y& y) {
    x = x + y;
    y = x - y;
    x = x - y;
}
// end of Anuj Bhati's aka papaji310's Template
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        umii v;
        Rep(i, nums.size()) {
            v[nums[i]]++;
            if (v[nums[i]] > 1)
                return true;
        }
        return false;
    }
};