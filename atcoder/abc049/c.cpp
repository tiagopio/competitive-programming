#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    string tmp;
    for (int i = s.length() - 1; i >= 0; i--) {
        tmp.push_back(s[i]);
        if (tmp == "resare" or tmp == "esare" or tmp == "remaerd" or tmp == "maerd") tmp.clear();
    }
    cout << ((tmp.empty()) ? "YES\n" : "NO\n");
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
    Check backwards
}}}*/