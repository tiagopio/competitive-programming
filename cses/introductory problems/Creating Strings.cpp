#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; 
  cin >> s;
  vector<string> ans;
  
  sort(s.begin(), s.end());
  do {
    ans.push_back(s);
  } while (next_permutation(s.begin(), s.end()));
  
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << '\n';
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
