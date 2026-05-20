#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, T;
    cin >> N >> T;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    map<int, int> mp;
    int mx = a[N - 1];
    int max_prof = 1;
    for (int i = N - 2; i >= 0; i--) {
        if (mx - a[i] > 0) {
            max_prof = max(max_prof, mx - a[i]);
            mp[mx - a[i]]++;
        }
        mx = max(mx, a[i]);
    }
    cout << mp[max_prof] << '\n';
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
    Decrease the number of max profits
}}} */