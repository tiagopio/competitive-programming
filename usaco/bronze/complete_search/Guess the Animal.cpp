#include <bits/stdc++.h>
using namespace std;

#define int long long

template <typename T> set<T> intersection(const set<T> &s1, const set<T> &s2) {
	set<T> ret;
	for (const T &i : s1) {
		if (s2.count(i)) { ret.insert(i); }
	}
	return ret;
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("guess");
    int n;
    cin >> n;
    vector<set<string>> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        int k;
        cin >> s >> k;
        for (int j = 0; j < k; j++) {
            string x;
            cin >> x;
            a[i].insert(x);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<string> cmn = intersection(a[i], a[j]);
            ans = max(ans, (int)cmn.size() + 1);
        }
    }
    cout << ans << '\n';
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