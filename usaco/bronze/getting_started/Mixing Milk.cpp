#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("mixmilk");
    // capacity, current
    vector<pair<int, int>> p(4);
    for (int i = 1; i <= 3; i++) cin >> p[i].first >> p[i].second;
    for (int i = 1; i <= 100; i++) {
        int r = i % 3;
        if (r == 0) {
            int can = p[1].first - p[1].second;
            int put = min(p[3].second, can);
            p[3].second -= put;
            p[1].second += put;
        } else if (r == 1) {
            int can = p[2].first - p[2].second;
            int put = min(p[1].second, can);
            p[1].second -= put;
            p[2].second += put;
        }  else {
            int can = p[3].first - p[3].second;
            int put = min(p[2].second, can);
            p[2].second -= put;
            p[3].second += put;
        }
    }
    for (int i = 1; i <= 3; i++) cout << p[i].second << '\n';
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