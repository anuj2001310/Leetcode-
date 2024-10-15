#define ll long long
#define FOR (a, b, c) for (int a = b; a < c; ++a)

long long minimumSteps(char* s) {
    ll ans = 0, r = 0;
    for (; *s; s++) {
        if ((*s) == '1')
            r++;
        else
            ans += r;
    }
    return ans;
}