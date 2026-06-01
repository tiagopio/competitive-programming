#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    bool ok = false;
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            bool eq = true;
            for (int k = 0; k < M; k++) for (int l = 0; l < M; l++) eq &= (A[i + k][j + l] == B[k][l]);
            ok |= eq;
        }
    }
    cout << ((ok) ? "Yes\n" : "No\n");
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/* Solution Notes {{{
    Look all the submatrices of size M contained in A.
}}}*/