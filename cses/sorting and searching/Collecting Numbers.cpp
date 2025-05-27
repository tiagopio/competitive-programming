#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos[x] = i;
    }
    int ans = 0, target = 1;
    while(target <= n) {
        while(target + 1 <= n and pos[target + 1] > pos[target]) target++;
        ans++;
        target++;
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
