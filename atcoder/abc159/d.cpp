#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), rec(n + 1, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        rec[a[i]]++;
    }
    int total = 0;
    for (int i = 0; i <= n; i++) total += ((rec[i] * (rec[i] - 1)) / 2);
    for (int i = 0; i < n; i++) {
        int v = (rec[a[i]] * (rec[a[i]] - 1)) / 2;
        total -= v;
        int x = rec[a[i]] - 1;
        int nv = x * (x - 1) / 2;
        cout << total + nv << '\n';
        total += v;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(12);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

/* Solution Notes {{{

    (qtd(a[1])) + (qtd(a[2])) + ... + (qtd(a[n])) 
    (    2    )   (    2    )         (    2    )

}}} */