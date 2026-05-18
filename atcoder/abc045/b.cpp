#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    char curr = 'a';
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    while(true) {
        if (curr == 'a') {
            if (!a.size()) break;
            curr = a.back();
            a.pop_back();
        }
        else if (curr == 'b') {
            if (!b.size()) break;
            curr = b.back();
            b.pop_back();
        }
        else if (curr == 'c') {
            if (!c.size()) break;
            curr = c.back();
            c.pop_back();
        }
    }
    if (curr == 'a') cout << "A\n";
    if (curr == 'b') cout << "B\n";
    if (curr == 'c') cout << "C\n";
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
    Simulate the game
}}} */