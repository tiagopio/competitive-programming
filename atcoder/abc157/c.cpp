#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, char>> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i].first >> A[i].second;
        A[i].first--;
    }
    int l = 1, r = 0;
    for (int i = 0; i < N; i++) l *= 10, r = r * 10 + 9;
    l /= 10;
    if (l == 1) l = 0;
    for (int i = l; i <= r; i++) {
        bool ok = true;
        string s = to_string(i);
        for (int j = 0; j < M; j++) ok &= (s[A[j].first] == A[j].second);
        if (ok) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
