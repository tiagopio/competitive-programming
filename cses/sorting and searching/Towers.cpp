#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> towers;
    towers.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        int l = 0, r = towers.size() - 1, ans = -1;
        while(l <= r) {
            int m = (l + r) / 2;
            if (towers[m] > a[i]) {
                ans = m;
                r = m - 1;
            } else l = m + 1;
        }
        if (ans == -1) towers.push_back(a[i]);
        else towers[ans] = a[i];
    }
    cout << towers.size() << '\n';
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
