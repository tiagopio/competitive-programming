#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6+10;
const int m = 1e9+7;

int factorial[MAXN];

int fexp(int x, int y) {
    int r = 1;
    while(y) {
        if (y & 1) r = (r * x) % m;
        y >>= 1;
        x = (x * x) % m;
    }
    return r;
}

int inv(int x) {
    return fexp(x, m - 2);
}

void prep() {
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }
}

int binomial_coefficient(int n, int k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % m) % m;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << binomial_coefficient(a, b) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prep();

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}