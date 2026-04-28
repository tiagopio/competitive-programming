#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN = 1010;
const int INF = 0x3f3f3f3f3f3f3f3f;

int N, SZ, P, U[MAXN][MAXN];
char G[MAXN][MAXN];

void floodfill(int i, int j) {
    if (i < 0 or i >= N or j < 0 or j >= N) { P++; return; }
    if (G[i][j] == '.') { P++; return; }
    if (U[i][j]) return;
    U[i][j] = 1;
    SZ++;
    floodfill(i + 1, j);
    floodfill(i - 1, j);
    floodfill(i, j + 1);
    floodfill(i, j - 1);
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> G[i][j];
    int ans = 0, per = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!U[i][j] and G[i][j] == '#') {
                SZ = 0;
                P = 0;
                floodfill(i, j);
                if (SZ > ans) {
                    ans = SZ;
                    per = P;
                } else if (SZ == ans) {
                    per = min(per, P);
                }
            }
        }
    }
    cout << ans << ' ' << per << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("perimeter");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}