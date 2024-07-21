#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;

void hanoi(int n, int init, int aux, int dst) {
  if (n == 1) {
    ans.emplace_back(init, dst);
    return;
  }
  hanoi(n - 1, init, dst, aux);
  hanoi(1, init, aux, dst);
  hanoi(n - 1, aux, init, dst);
}

void solve() {
  int k;
  cin >> k;

  hanoi(k, 1, 2, 3);
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i.first << " " << i.second << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
