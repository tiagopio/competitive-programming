#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

using pii = pair<int, int>;

int area(vector<pii> &a) {
    int tmp = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i != j and j != k and i != k) {
                    if (a[i].second == a[j].second and a[i].first == a[k].first) {
                        tmp = max(tmp, abs(a[i].first - a[j].first) * abs(a[i].second - a[k].second));
                    }
                }
            }
        }
    }
    return tmp;
}

void solve() {
    setIO("triangles");
    int n;
    cin >> n;
    vector<pii> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                vector<pii> v;
                v.push_back(p[i]);
                v.push_back(p[j]);
                v.push_back(p[k]);
                ans = max(ans, area(v));
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