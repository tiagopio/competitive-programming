#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e7+10;
vector<int> primes;
vector<int> primo(N + 1, 1);

void sieve() {
    for (int x = 2; x <= N; x++) {
        if (primo[x]) {
            for (int y = x + x; y <= N; y += x) {
                primo[y] = 0;
            }
        }
    }
    for (int i = 2; i < N; i++) if (primo[i]) primes.push_back(i);
}

void solve() {
    sieve();
    cout << primes[0] << '\n';
    cout << primes[5] << '\n';
    cout << primes[10000] << '\n';
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