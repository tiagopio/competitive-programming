#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    char c;
    cin >> c;
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') cout << "vowel\n";
    else cout << "consonant\n";
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
    if else
}}}*/