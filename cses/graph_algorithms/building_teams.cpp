#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+10;

int n, m;
bool used[N]; 
int color[N];
vector<int> graph[N];

void dfs(int s, int c) {
    used[s] = true;
    color[s] = c;
    for (auto u : graph[s]) {
        if (!used[u]) dfs(u, c ^ 1);
        else {
            if (color[s] == color[u]) {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!used[i]) dfs(i, 0);
    for (int i = 1; i <= n; i++) cout << color[i] + 1 << ' ';
    cout << '\n';
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
    
    Check if the graph is bipartite

    Complexity: O(n + m) dfs

    Task:	Building Teams
    Sender:	tiago
    Submission time:	2026-04-05 18:34:41 +0300
    Language:	C++ (C++20)
    Status:	READY
    Result:	ACCEPTED
    
}}} */