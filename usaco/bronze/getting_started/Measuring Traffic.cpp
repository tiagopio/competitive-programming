#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("traffic");
    int N, A[100], B[100];
    string T[100];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> T[i] >> A[i] >> B[i];
    int a = 0, b = 0x3f3f3f3f3f3f3f3f;
    for (int i = N - 1; i >= 0; i--) {
        if (T[i] == "none") {
            a = max(a, A[i]);
            b = min(b, B[i]);
        }
        if (T[i] == "off") {
            a += A[i];
            b += B[i];
        }
        if (T[i] == "on") {
            a -= B[i];
            b -= A[i];
            a = max(0LL, a);
        }
    }
    cout << a << ' ' << b << '\n';
    a = 0, b = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < N; i++) {
        if (T[i] == "none") {
            a = max(a, A[i]);
            b = min(b, B[i]);
        }
        if (T[i] == "on") {
            a += A[i];
            b += B[i];
        }
        if (T[i] == "off") {
            a -= B[i];
            b -= A[i];
            a = max(0LL, a);
        }
    }
    cout << a << ' ' << b << '\n';
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