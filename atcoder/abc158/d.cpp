#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string S;
    int Q;
    cin >> S >> Q;
    deque<char> ans;
    for (auto c : S) ans.push_back(c);
    bool r = false;
    while(Q--) {
        int T;
        cin >> T;
        if (T == 1) r = !r;
        else {
            int F;
            char c;
            cin >> F >> c;
            if (r) {
                if (F == 1) ans.push_back(c);
                else ans.push_front(c);
            } else {
                if (F == 1) ans.push_front(c);
                else ans.push_back(c);
            }
        }
    }
    if (r) reverse(ans.begin(), ans.end());
    for (auto c : ans) cout << c;
    cout << '\n';
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