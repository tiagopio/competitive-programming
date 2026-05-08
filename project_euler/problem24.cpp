#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    vector<int> p = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int id = 1;
    do {
        if (id == 1e6) {
            for (auto u : p) cout << u;
            cout << '\n';
        }
        id++;
    } while(next_permutation(p.begin(), p.end()));
    cout << id << '\n';
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
