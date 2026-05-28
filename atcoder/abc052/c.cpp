#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

void solve() {
	int n;
	cin >> n;
	map<int, int> freq;
	for (int i = 2; i <= n; i++) {
		int num = i;
		for (int j = 2; j * j <= num; j++) {
			while(num % j == 0) {
				freq[j]++;
				num /= j;
			}
		}
		if (num != 1) freq[num]++;
	}
	int ans = 1;
	for (auto i : freq) {
		ans *= i.second + 1;
		ans %= mod;
	}
	cout << ans << '\n';
}


int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

/* Solution Notes {{{
    product of every factor between 2...N
}}}*/