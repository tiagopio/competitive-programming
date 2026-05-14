#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (auto i : a) cout << i;
    cout << '\n';
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}