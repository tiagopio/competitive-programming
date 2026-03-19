#include <bits/stdc++.h>
using namespace std;

#define int long long

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return x >= 2;
}

void solve() {
    int num = 600851475143;
    int mx = 0;
    for (int f = 2; f * f <= num; f++) {
        if (num % f == 0) {
            mx = f;
            while(num % f == 0) num /= f;
        }
    }
    if (is_prime(num)) cout << max(mx, num) << '\n';    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}