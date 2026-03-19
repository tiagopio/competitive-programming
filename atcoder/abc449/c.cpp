#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, L, R;
    string S;
    S = " ";
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        S.push_back(c);
    }
    vector<int> rec(26, 0);
    int ans = 0;
    int left = 1 + L, rigth = 1 + R;
    for (int i = left; i <= rigth; i++) rec[S[i] - 'a']++;
    ans += rec[S[1] - 'a'];
    for (int i = 2; i <= N and left <= N; i++) {
        rec[S[left] - 'a']--;
        left++, rigth++;
        if (rigth <= N) rec[S[rigth] - 'a']++;
        ans += rec[S[i] - 'a'];
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