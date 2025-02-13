#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m)), prefix(n + 1, vector<int>(m));

  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];
  
  for (int j = 0; j < m; j++) {
    vector<int> col;
    for (int i = 0; i < n; i++) col.push_back(grid[i][j]);
    sort(col.begin(), col.end());
    for (int i = 0; i < n; i++) grid[i][j] = col[i];
  }

  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) prefix[i + 1][j] = prefix[i][j] + grid[i][j];

  int ans = 0;
  for (int i = 0; i < n - 1; i++) for (int j = 0; j < m; j++) ans += abs((n - i - 1) * grid[i][j] - (prefix[n][j] - prefix[i + 1][j]));
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}

/* Solution Notes:

   Calculation:
     6 + 5 + 0 + 7 + 1
     2 + 4 + 3 + 5 + 4

   Resulting sums per column:
     8   9   3   12  5 = 37

   Based on this, we can see that a prefix sum grid can be used.
   Therefore, the sum for each row is given by the summation of
     abs((n - i - 1) * grid[i][j] - (prefix[n][col] - prefix[i + 1][j]));

   For example:

   Original Grid:
     1  4  2  8  5
     7  9  2  1  4
     3  8  5  3  1

   Prefix Sum Grid:
     0  0  0  0  0
     1  4  2  8  5
     8  13 4  9  9
     11 21 9  12 10

   For the first row:
     2 * 1 - 10 = 8
     2 * 4 - 17 = 9
     2 * 2 - 7  = 3
     2 * 8 - 4  = 12
     2 * 5 - 5  = 5
   -----------------------
               Total = 37

  looks good...
*/
