#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << ((a[0] + a[1] == a[2]) ? "Yes\n" : "No\n");   
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
    sort the packs 
    the sum of a[0] + a[1] should be a[2]
}}} */