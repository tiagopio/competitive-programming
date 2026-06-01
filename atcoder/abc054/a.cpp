#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int A, B;
    cin >> A >> B;
    vector<int> cards(14);
    cards[2] = 0;
    cards[3] = 1;
    cards[4] = 2;
    cards[5] = 3;
    cards[6] = 4;
    cards[7] = 5;
    cards[8] = 6;
    cards[9] = 7;
    cards[10] = 8;
    cards[11] = 9;
    cards[12] = 10;
    cards[13] = 11;
    cards[1] = 12;
    if (cards[A] == cards[B]) cout << "Draw\n";
    else if (cards[A] > cards[B]) cout << "Alice\n";
    else cout << "Bob\n"; 
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
    map each card to an number
}}}*/