#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int sum = a[i] + a[i + 1];
        int diff = max(0ll, sum - x);
        ans += diff;
        a[i + 1] = max(a[i + 1] - diff, 0LL);
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

/* Solution Notes {{{
    For each i it's better subtract in i + 1
}}} */