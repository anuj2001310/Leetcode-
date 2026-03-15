typedef long long ll;
long long countCommas(long long n) {
    ll a = 0;
    ll b = 1000;

    while (b <= n)
        a += (n - b + 1), b *= 1000;
        
    return a;
}