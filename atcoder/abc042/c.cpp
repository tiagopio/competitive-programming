#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> st;
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i <= 9; i++) st.insert(i);
    for (int i = 0; i < k; i++) {
        if (st.find(a[i]) != st.end()) st.erase(a[i]);
    }
    int ans = 1e9;
    // mm, m, c, d, u
    for (auto i : st) {
        int tmp1 = 0;
        tmp1 += i;
        if (tmp1 >= n) ans = min(ans, tmp1);
        for (auto j : st) {
            int tmp2 = 0;
            tmp2 += 10 * i;
            tmp2 += j;
            if (tmp2 >= n) ans = min(ans, tmp2);
            for (auto k : st) {
                int tmp3 = 0;
                tmp3 += 100 * i;
                tmp3 += 10 * j;
                tmp3 += k;
                if (tmp3 >= n) ans = min(ans, tmp3);
                for (auto l : st) {
                    int tmp4 = 0;
                    tmp4 += 1000 * i;
                    tmp4 += 100 * j;
                    tmp4 += 10 * k;
                    tmp4 += l;
                    if (tmp4 >= n) ans = min(ans, tmp4);
                    for (auto m : st) {
                        int tmp5 = 0;
                        tmp5 += 10000 * i;
                        tmp5 += 1000 * j;
                        tmp5 += 100 * k;
                        tmp5 += 10 * l;
                        tmp5 += m;
                        if (tmp5 >= n) ans = min(ans, tmp5);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}