#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX = 21;

int n;
char grid[MAX][MAX];
bool used[MAX][MAX];
vector<tuple<int, int, int, int>> pcl;

bool check(int i, int j, int sx, int sy, int N, int M) {
    return i >= sx and i < N and j >= sy and j < M;
}

void floodfill(int i, int j, int sx, int sy, int N, int M, char last) {
    if (!check(i, j, sx, sy, N, M)) return;
    if (grid[i][j] != last) return;
    if (used[i][j]) return;
    used[i][j] = true;
    floodfill(i + 1, j, sx, sy, N, M, grid[i][j]);
    floodfill(i - 1, j, sx, sy, N, M, grid[i][j]);
    floodfill(i, j + 1, sx, sy, N, M, grid[i][j]);
    floodfill(i, j - 1, sx, sy, N, M, grid[i][j]);
}

void is_pcl(int sx, int sy, int ex, int ey) {
    memset(used, 0, sizeof(used));
    map<char, int> color_comp;
    for (int i = sx; i <= ex; i++) {
        for (int j = sy; j <= ey; j++) {
            if (!used[i][j]) {
                color_comp[grid[i][j]]++;
                floodfill(i, j, sx, sy, ex + 1, ey + 1, grid[i][j]);
            }
        }
    }
    if (color_comp.size() == 2) {
        auto it = color_comp.begin();
        int comp1 = it->second;
        int comp2 = next(it)->second;
        
        if ((comp1 == 1 && comp2 >= 2) || (comp2 == 1 && comp1 >= 2)) {
            pcl.push_back({sx, sy, ex, ey});
        }
    }
}

void subgrid(int r, int c) {
    for (int i = 0; i <= n - r; i++) for (int j = 0; j <= n - c; j++) is_pcl(i, j, i + r - 1, j + c - 1);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
    for (int r = 1; r <= 20; r++) for (int c = 1; c <= 20; c++) subgrid(r, c);
    int ans = 0;
    for (int i = 0; i < pcl.size(); i++) {
        bool is_max = true;
        for (int j = 0; j < pcl.size(); j++) {
            if (i == j) continue;
            auto [fx, fy, fe, fg] = pcl[i];
            auto [sx, sy, se, sg] = pcl[j];
            if (fx >= sx and fe <= se and fy >= sy and fg <= sg) {
                is_max = false;
                break;
            }
        }
        if (is_max) ans++;
    }
    cout << ans << '\n';    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("where");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}