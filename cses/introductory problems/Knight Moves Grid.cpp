/*
	Task:	Knight Moves Grid
	Sender:	tiagopio
	Submission time:	2025-05-19 19:47:45 +0300
	Language:	C++ (C++20)
	Status:	READY
	Result:	ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> d;
vector<vector<bool>> used;

int steps[2][8] = {
	{-2, -1, 1, 2, -2, -1, 1, 2},
	{-1, -2, -2, -1, 1, 2, 2, 1}
};

bool check(int i, int j) {
	return i >= 0 and i < n and j >= 0 and j < n and !used[i][j];
}

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.emplace(i, j);
	d[i][j] = 0;
	used[i][j] = true;

	while(!q.empty()) {
		auto v = q.front();
		q.pop();

		for (int k = 0; k < 8; k++) {
			int x = v.first + steps[0][k];
			int y = v.second + steps[1][k];
			if (check(x, y)) {
				q.emplace(x, y);
				d[x][y] = d[v.first][v.second] + 1;
				used[x][y] = true;
			}
		}
	}
}

void solve() {
	cin >> n;
	d.resize(n, vector<int>(n));
	used.resize(n, vector<bool>(n, false));
	bfs(0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
    return 0;
}
