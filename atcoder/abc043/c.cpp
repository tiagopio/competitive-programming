#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> a;

int cost(int x) {
    int tmp = 0;
    for (int i = 0; i < n; i++) tmp += ((a[i] - x) * (a[i] - x));
    return tmp;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = -1000; i <= 1000; i++) {
        int tmp_ans = 0;
        for (int j = 0; j < n; j++) tmp_ans += (a[j] - i) * (a[j]  - i);
        ans = min(ans, tmp_ans);
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