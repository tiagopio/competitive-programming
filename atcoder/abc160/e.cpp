#include <bits/stdc++.h>
using namespace std;

#define int long long

int X, Y, A, B, C;
vector<int> r, g, c;

void solve() {
    cin >> X >> Y >> A >> B >> C;
    for (int i = 0; i < A; i++) {
        int x; cin >> x;
        r.push_back(x);
    }
    for (int i = 0; i < B; i++) {
        int x; cin >> x;
        g.push_back(x);
    }
    for (int i = 0; i < C; i++) {
        int x; cin >> x;
        c.push_back(x);
    }
    sort(r.rbegin(), r.rend());
    sort(g.rbegin(), g.rend());
    sort(c.rbegin(), c.rend());
    int ans = 0;
    vector<int> pe;
    for (int i = 0; i < X; i++) ans += r[i], pe.push_back(r[i]);
    for (int i = 0; i < Y; i++) ans += g[i], pe.push_back(g[i]);
    sort(pe.begin(), pe.end());
    for (int i = 0; i < min(C, X + Y); i++) ans = max(ans, ans - pe[i] + c[i]);
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

    greedy, take the X max elements from A
    Y max elements from B
    then for each best C apple remove the minimum
    element from the set {X + Y}

    Complexity: O((X + Y) * log(X + Y))

}}} */