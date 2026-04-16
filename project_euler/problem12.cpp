#include <bits/stdc++.h>
using namespace std;

#define int long long

int qtd(int x) {
    set<int> st;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            st.insert(i);
            st.insert(x / i);
        }
    }
    return (int)st.size();
}

void solve() {
    int sum = 0;
    int num = 1;
    while(qtd(sum) <= 500) sum += num++;
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