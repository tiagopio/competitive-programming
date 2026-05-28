#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int A; cin >> A;
        mp[A]++;
    }
    for (auto &u : mp) {
        if (u.second & 1) u.second = 1;
        else u.second = 2;
    }
    int qtd_even = 0;
    for (auto u : mp) qtd_even += (u.second % 2 == 0);
    cout << mp.size() - (qtd_even % 2) << '\n';
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
    First, we remove the identical elements 
    until the quantity of each element is 1 or 2. 
    The final answer will be the 
    number of distinct elements - the number of elements
    with quantity 2 mod 2
}}}*/