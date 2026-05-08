#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e7+10;

bool primes[N + 1];

void solve() {
    for (int i = 1; i < N; i++) primes[i] = true;
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= N; j += i)
                primes[j] = false;
        }
    }

    int ans = 0, qtd = 0;
    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int tmp = 0;
            for (int n = 0; n <= 100; n++) {
                if (n * n + a * n + b < N and n * n + a * n + b >= 0) tmp += primes[n * n + a * n + b];
            }
            if (tmp > qtd) {
                qtd = tmp;
                ans = a * b;
            }
        }
    }
    cout << ans << '\n';
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
