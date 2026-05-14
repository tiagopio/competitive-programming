#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int N = 51;

int n, A;
int a[N];
int dp[N][N * N][N];

int f(int i, int sum, int qtd) {
	if (i >= n) return (qtd and sum % qtd == 0 and sum / qtd == A);
	if (dp[i][sum][qtd] != -1) return dp[i][sum][qtd];
	dp[i][sum][qtd] = 0;
	dp[i][sum][qtd] += f(i + 1, sum, qtd) + f(i + 1, sum + a[i], qtd + 1);	
	return dp[i][sum][qtd];
}

void solve() {
	cin >> n >> A;
	for (int i = 0; i < n; i++) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0, 0) << '\n';
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
