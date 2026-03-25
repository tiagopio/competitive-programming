#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        a.emplace_back(u, v, i);
    }
    sort(a.begin(), a.end());
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int k = 1;
    for (int i = 0; i < n; i++) {
        auto [A, B, id] = a[i];
        if (pq.empty()) {
            ans[id] = k;
            pq.emplace(B, A, k++);
        } else {
            auto [r, l, q] = pq.top();
            if (r < A) {
                pq.pop();
                pq.emplace(B, A, q);
                ans[id] = q;
            } else {
                ans[id] = k;
                pq.emplace(B, A, k++);
            }
        }
    }
    set<int> st;
    for (auto i : ans) st.insert(i);
    cout << st.size() << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
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

    1 2
    2 4
    4 4

    pq = {(2, 1, 1), (4, 2, 2)}

}}} */