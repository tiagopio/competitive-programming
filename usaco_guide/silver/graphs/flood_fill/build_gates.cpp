#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX = 5000;

int n;
string s;
char grid[MAX][MAX];
bool used[MAX][MAX];

bool check(int i, int j) {
    return i >= 0 and i < MAX and j >= 0 and j < MAX and !used[i][j] and grid[i][j] == '.';
}

int steps[2][4] = {
    {0, 1, -1, 0},
    {1, 0, 0, -1}
};

void floodfill(int i, int j) {
    queue<pair<int, int>> q;
    q.emplace(i, j);
    used[i][j] = true;
    while(!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = steps[0][k] + v.first;
            int y = steps[1][k] + v.second;
            if (check(x, y)) {
                q.emplace(x, y);
                used[x][y] = true;
            }
        }
    }
}

void solve() { 
    cin >> n >> s;
    int x = MAX / 2, y = MAX / 2;
    for (int i = 0; i < MAX; i++) for (int j = 0; j < MAX; j++) grid[i][j] = '.';
    grid[x][y] = '#';
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') x--;
        if (s[i] == 'S') x++;
        if (s[i] == 'E') y++;
        if (s[i] == 'W') y--;
        grid[x][y] = '#';
        if (s[i] == 'N') x--;
        if (s[i] == 'S') x++;
        if (s[i] == 'E') y++;
        if (s[i] == 'W') y--;
        grid[x][y] = '#';
    }
    int comp = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (!used[i][j] and grid[i][j] == '.') {
                comp++;
                floodfill(i, j);
            }
        }
    }
    cout << comp - 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("gates");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}