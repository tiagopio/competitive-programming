#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;
const int N = 1e5+10;

int h, w, a, b;
int fat[2 * N];

int pow(int x, int y, int m) { 
    int ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

int C(int n, int k) {
    return fat[n] * pow(fat[k], mod - 2, mod) % mod * pow(fat[n - k], mod - 2, mod) % mod;
}

void solve() {
    cin >> h >> w >> a >> b;
    int ans = 0;
    for (int l = 0; l < h - a; l++) {
        int left = C(l + b - 1, l);
        int right = C((h - l - 1) + (w - b - 1), h - l - 1);
        ans = (ans + left * right) % mod;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fat[0] = 1;
    for (int i = 1; i < 2 * N; i++) {
        fat[i] = fat[i - 1] * i;
        fat[i] %= mod;
    }

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}