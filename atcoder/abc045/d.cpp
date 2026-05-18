#include <bits/stdc++.h>
using namespace std;

#define int long long

int h, w, n;
vector<pair<int, int>> a;

bool check(int i, int j) {
    return i >= 0 and i < h and j >= 0 and j < w;
}

void solve() {
    cin >> h >> w >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;
    }
    set<pair<int, int>> st;
    for (auto u : a) st.insert(u);
    set<pair<int, int>> valid;
    for (int i = 0; i < n; i++) {
        int x = a[i].first, y = a[i].second;
        // se o cara é 0,0
        if (
            check(x, y)     and check(x, y + 1)     and check(x, y + 2) and
            check(x + 1, y) and check(x + 1, y + 1) and check(x + 1, y + 2) and 
            check(x + 2, y) and check(x + 2, y + 1) and check(x + 2, y + 2)
        ) valid.emplace(x, y);

        // se o cara é 0,1
        if (
            check(x, y - 1)     and check(x, y)     and check(x, y + 1) and
            check(x + 1, y - 1) and check(x + 1, y) and check(x + 1, y + 1) and 
            check(x + 2, y - 1) and check(x + 2, y) and check(x + 2, y + 1)
        ) valid.emplace(x, y - 1);

        // se o cara é 0,2
        if (
            check(x, y - 2)     and check(x, y - 1)     and check(x, y) and
            check(x + 1, y - 2) and check(x + 1, y - 1) and check(x + 1, y) and 
            check(x + 2, y - 2) and check(x + 2, y - 1) and check(x + 2, y)
        ) valid.emplace(x, y - 2);

        // se o cara é 1,0
        if (
            check(x - 1, y) and check(x - 1, y + 1)  and check(x - 1, y + 2) and
            check(x, y)     and check(x, y + 1)      and check(x, y + 2) and 
            check(x + 1, y) and check(x + 1, y  + 1) and check(x + 1, y + 2)
        ) valid.emplace(x - 1, y);
        
        // se o cara é 1,1
        if (
            check(x - 1, y - 1) and check(x - 1, y)  and check(x - 1, y + 1) and
            check(x, y - 1)     and check(x, y)      and check(x, y + 1) and 
            check(x + 1, y - 1) and check(x + 1, y)  and check(x + 1, y + 1)
        ) valid.emplace(x - 1, y - 1);
        
        // se o cara é 1,2
        if (
            check(x - 1, y - 2) and check(x - 1, y - 1)  and check(x - 1, y) and
            check(x, y - 2)     and check(x, y - 1)      and check(x, y) and 
            check(x + 1, y - 2) and check(x + 1, y - 1)  and check(x + 1, y)
        ) valid.emplace(x - 1, y - 2);
        
        // se o cara é 2,0
        if (
            check(x - 2, y) and check(x - 2, y + 1)  and check(x - 2, y + 2) and
            check(x - 1, y) and check(x - 1, y + 1)  and check(x - 1, y + 2) and 
            check(x, y)     and check(x, y + 2)      and check(x, y + 2)
        ) valid.emplace(x - 2, y);
    
        // se o cara é 2,1
        if (
            check(x - 2, y - 1) and check(x - 2, y)  and check(x - 2, y + 1) and
            check(x - 1, y - 1) and check(x - 1, y)  and check(x - 1, y + 1) and 
            check(x, y - 1)     and check(x, y)      and check(x, y + 1)
        ) valid.emplace(x - 2, y - 1);
    
        // se o cara é 2,2
        if (
            check(x - 2, y - 2) and check(x - 2, y - 1)  and check(x - 2, y) and
            check(x - 1, y - 2) and check(x - 1, y - 1)  and check(x - 1, y) and 
            check(x, y - 2)     and check(x, y - 1)      and check(x, y)
        ) valid.emplace(x - 2, y - 2);
    }
    vector<int> ans(10, 0);
    int steps[2][9] = {
        {0, 0, 0, 1, 1, 1, 2, 2, 2},
        {0, 1, 2, 0, 1, 2, 0, 1, 2}
    };
    for (auto [x, y] : valid) {
        int count = 0;
        for (int k = 0; k < 9; k++) count += st.count({x + steps[0][k], y + steps[1][k]});
        ans[count]++;
    }
    int sum = accumulate(ans.begin(), ans.end(), 0LL);
    ans[0] = max(0ll, h - 2) * max(0ll, w - 2) - sum;
    for (auto i : ans) cout << i << '\n';
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
    We can go through each painted point
    and consider it to be one of the possible
    positions in a 3x3 square, we keep all the possible
    starting positions and count them.    
}}} */