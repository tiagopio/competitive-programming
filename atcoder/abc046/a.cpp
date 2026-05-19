#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    set<int> st;
    for (int i = 0; i < 3; i++) {
        int x; cin >> x;
        st.insert(x);
    }
    cout << st.size() << '\n';
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
    Add the colors in a set
    the ans = st.size()
}}} */