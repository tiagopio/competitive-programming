#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("lifeguards");
    int n;
    cin >> n;
    using pii = pair<int, int>;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto p = a[i];
        a.erase(a.begin() + i);
        int tmp = 0;
        for (int j = 0; j < n - 1; j++) {
            int k = j, l = a[k].first, r = a[k].second;
            while(k + 1 < n - 1 and r >= a[k + 1].first) {
                k++;
                r = a[k].second;
            }
            tmp += (r - l);
            j = k;
        }
        ans = max(ans, tmp);
        a.insert(a.begin() + i, p);
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