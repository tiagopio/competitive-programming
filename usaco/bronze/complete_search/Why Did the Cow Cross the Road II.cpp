#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("circlecross");
    string s;
    cin >> s;
    vector<vector<int>> v(26);
    for (int i = 0; i < s.length(); i++) v[s[i] - 'A'].push_back(i);
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if(i != j) {
                ans += (v[i][0] < v[j][0] and v[i][1] < v[j][1] and v[i][1] > v[j][0]);
            }
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