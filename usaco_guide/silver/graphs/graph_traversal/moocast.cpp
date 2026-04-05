#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 210;

int n;
tuple<int, int, int> graph[N];
bool used[N];

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int dfs(int s) {
    int vis = 1;
    auto [a, b, P] = graph[s];
    used[s] = true;
    for (int i = 0; i < n; i++) {
        if (i != s and !used[i]) {
            auto [x, y, P2] = graph[i];
            if ((x - a) * (x - a) + (b - y) * (b - y) <= P) {
                vis += dfs(i);
            }
        }
    }
    return vis;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, p; cin >> a >> b >> p;
        graph[i] = make_tuple(a, b, p * p);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) used[j] = false;
        ans = max(ans, dfs(i));
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("moocast");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

/* Solution Notes {{{

    We can initiate a DFS for each cow to count the number 
    of reachable cows, then return the maximum value found.

    Complexity: O(n * (n + m))

}}} */