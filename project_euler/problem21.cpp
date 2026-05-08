#include <bits/stdc++.h>
using namespace std;

#define int long long

int sum_of_divs(int x) {
    set<int> divs;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.insert(i);
            divs.insert(x / i);
        }
    }
    int ret = 0;
    for (auto u : divs) ret += u;
    return ret - x;
}

bool ok(int x) {
    int sum = sum_of_divs(x);
    return (sum_of_divs(sum) == x and x != sum);
}

void solve() {
    int sum = 0;
    for (int i = 1; i < 10000; i++) {
        if (ok(i)) sum += i;
    }
    cout << sum << '\n';
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
