#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, M;
    cin >> N >> M;
    set<pair<int, int>> edges;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges.emplace(a, b);
        edges.emplace(b, a);
    }
    vector<int> path;
    for (int i = 1; i <= N; i++) path.push_back(i);
    int ans = 0;
    do {
        bool ok = true;
        for (int i = 0; i < path.size() - 1; i++) ok &= (edges.count({path[i], path[i + 1]}));
        ans += (ok and path[0] == 1);
    } while(next_permutation(path.begin(), path.end()));
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/* Solution Notes {{{
    Analyze all permutations of the path that begin 
    with 1 and check if all edges exist.
}}}*/