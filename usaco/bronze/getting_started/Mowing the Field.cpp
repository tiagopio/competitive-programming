#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("mowing");
    int n;
    cin >> n;
    int x = 0, y = 0, time = 1;
    map<pair<int, int>, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        char d;
        int v;
        cin >> d >> v;
        while(v--) {
            if (d == 'N') y++;
            if (d == 'S') y--;
            if (d == 'E') x++;
            if (d == 'W') x--;    
            mp[{x, y}].push_back(time);
            time++;
        }
    }
    int ans = INF;
    for (auto i : mp) {
        for (int j = 0; j < i.second.size() - 1; j++) {
            ans = min(ans, i.second[j + 1] - i.second[j]);
        }
    }
    cout << ((ans == INF) ? -1 : ans) << '\n';
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