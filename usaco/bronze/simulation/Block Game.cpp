#include <bits/stdc++.h>
using namespace std;

const int MAX = 110;

string grid[MAX][2];
int ans[26];

void solve() {
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> grid[i][0] >> grid[i][1];
  }

  for (int i = 0; i < n; i++) {
    int freq1[26] = {0};
    int freq2[26] = {0};

    for (char c : grid[i][0]) {
      freq1[c - 'a']++;
    }
    for (char c : grid[i][1]) {
      freq2[c - 'a']++;
    }

    for (int j = 0; j < 26; j++) {
      ans[j] += max(freq1[j], freq2[j]);
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << ans[i] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
