#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<bool> used;
vector<int> color;
vector<vector<int>> graph;

void dfs(int s, int c) {
	used[s] = true;
	color[s] = c;
	for (auto u : graph[s]) {
		if (!used[u]) dfs(u, c ^ 1);
	}
}

void solve() {
	int n;
	cin >> n;
	used.resize(n + 1);
	color.resize(n + 1);
	graph.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	int red = 0, blue = 0;
	for (int i = 1; i <= n; i++) {
		if (color[i]) red++;
		else blue++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (color[i]) ans += blue - graph[i].size();
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