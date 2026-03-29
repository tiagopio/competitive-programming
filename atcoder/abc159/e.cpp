#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int h, w, K;
    cin >> h >> w >> K;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> grid[i][j];
    int ans = INF;
    for (int mask = 0; mask < (1LL << (h - 1)); mask++) {
        vector<int> cuts;
        for (int i = 0; i < h - 1; i++) {
            if ((mask >> i) & 1) cuts.push_back(i);
        }
        int blocks = cuts.size() + 1;
        vector<int> ones(blocks, 0);
        int vcuts = 0;
        bool ok = true;
        for (int j = 0; j < w; j++) {
            vector<int> col(blocks, 0);
            int blockid = 0;
            for (int i = 0; i < h; i++) {
                if (grid[i][j] == '1') col[blockid]++;   
                if (blockid < cuts.size() && i == cuts[blockid]) {
                    blockid++;
                }
            }
            for (int k = 0; k < blocks; k++) {
                if (col[k] > K) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
            bool need_cut = false;
            for (int k = 0; k < blocks; k++) {
                if (ones[k] + col[k] > K) {
                    need_cut = true;
                    break;
                }
            }
            if (need_cut) {
                vcuts++;
                for (int k = 0; k < blocks; k++) {
                    ones[k] = col[k]; 
                }
            } else {
                for (int k = 0; k < blocks; k++) {
                    ones[k] += col[k];
                }
            }
        }
        if (ok) {
            ans = min(ans, (int)cuts.size() + vcuts);
        }
    }
    cout << ans << '\n';
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
    bitmask rows
    + greedy columns
}}} */