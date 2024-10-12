// C++ Code
// Start Of Edwards310's Template...
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
using truth = bool;
using english = char;
using akt = int;
using decimal = float;
using ddecimal = double;
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
typedef vector<vvi> vvvi;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

#define FOR(a, b, c) for (int a = b; a < c; a++)
#define FOR1(a, b, c) for (int a = b; a <= c; ++a)
#define Rep(i, n) FOR(i, 0, n)
#define Rep1(i, n) FOR1(i, 1, n)
#define RepA(ele, nums) for (auto& ele : nums)
#define WHL(i, n) while (i < n)
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
#define umcs unordered_map<char, string>
#define umsc unordered_map<string, char>
#define umipii unordered_map<int, pii>
#define umpiii unordered_map<pii, int>
#define umivi unordered_map<int, vi>
#define umili unordered_map<int, list<int>>
#define umss unordered)map<string, string>
#define usi unordered_set<int>
#define usc unordered_set<char>
#define uss unordered_set<string>
#define sti stack<int>
#define stc stack<char>
#define sts stack<string>
#define stvi stack<vi>
#define stpii stack<pii>
#define qi queue<int>
#define qc queue<char>
#define qs queue<string>
#define qvi queue<vi>
#define qpii queue<pii>
#define qnode queue<TreeNode*>
#define mii map<int, int>
#define mpiii map<pii, int>
#define mipii map<int, pii>
#define mivi map<int, vi>
#define mllll map<LL, LL>
#define mci map<char, int>
#define mcc map<char, char>
#define msi map<string, int>
#define mss map<string, string>
#define vumii vector<umii>
template <class Y> void swap(Y& x, Y& y) {
    x = x + y;
    y = x - y;
    x = x - y;
}
template <typename X, typename Y> void add(X& x, Y& y) { return x + y; }
template <class T> class Stack {
public:
    int top;
    int size;
    T* arr;
    int capacity;
    Stack(int capacity) {
        this->capacity = capacity;
        this->top = -1;
        this->size = 0;
        this->arr = (T*)calloc(sizeof(T), capacity);
    }
    bool isEmpty() { return this->top == -1; }
    bool isFull() { return this->size == this->capacity; }
    void push(T val) {
        if (isEmpty())
            return;
        this->size++;
        this->top++;
        this->arr[this->top] = val;
    }
    T pop() {
        if (isFull())
            return NULL;
        T val = this->arr[this->top];
        this->size--;
        this->top--;
        return val;
    }
};
// End of Edwards310 Template
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vpii pairs;
        RepA (vec, intervals) {
            int x = vec[0], y = vec[1] + 1;
            pairs.pb({x, 1});
            pairs.pb({y, -1});
        }
        SORT(pairs);
        int cnt = 0, x = 0;
        for (auto& [_, f] : pairs) {
            x += f;
            cnt = fmax(cnt, x);
        }

        return cnt;
    }
};