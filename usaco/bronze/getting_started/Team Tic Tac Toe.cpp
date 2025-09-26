#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("tttt");
    vector<string> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];    
    set<string> ans1, ans2;
    for (int i = 0; i < 3; i++) {
        set<char> st;
        for (auto j : a[i]) st.insert(j);
        string tmp;
        for (auto j : st) tmp.push_back(j);
        if (st.size() == 1) ans1.insert(tmp);
        if (st.size() == 2) ans2.insert(tmp);
    }
    for (int i = 0; i < 3; i++) {
        set<char> st;
        for (int j = 0; j < 3; j++) {
            st.insert(a[j][i]);
        }
        string tmp;
        for (auto j : st) tmp.push_back(j);
        if (st.size() == 1) ans1.insert(tmp);
        if (st.size() == 2) ans2.insert(tmp);
    }
    set<char> st;
    st.insert(a[0][0]);
    st.insert(a[1][1]);
    st.insert(a[2][2]);
    string tmp;
    for (auto j : st) tmp.push_back(j); 
    if (st.size() == 1) ans1.insert(tmp);
    if (st.size() == 2) ans2.insert(tmp);
    tmp.clear();
    st.clear();
    st.insert(a[0][2]);
    st.insert(a[1][1]);
    st.insert(a[2][0]);
    for (auto j : st) tmp.push_back(j);
    if (st.size() == 1) ans1.insert(tmp);
    if (st.size() == 2) ans2.insert(tmp);
    cout << ans1.size() << '\n' << ans2.size() << '\n';
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