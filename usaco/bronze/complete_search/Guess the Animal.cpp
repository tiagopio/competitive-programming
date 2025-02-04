#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);
  
  int N;
  cin >> N;
  vector<vector<string>> characteristics(N);
  
  for (int i = 0; i < N; ++i) {
    string name;
    cin >> name;
    int K;
    cin >> K;
    for (int j = 0; j < K; ++j) {
      string characteristic;
      cin >> characteristic;
      characteristics[i].push_back(characteristic);
    }
  }
  
  int greatest_common = 0;
  
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int common = 0;
      for (const auto &characteristic1 : characteristics[i]) {
        for (const auto &characteristic2 : characteristics[j]) {
          if (characteristic1 == characteristic2) {
            common++;
            break;
          }
        }
      }
  
      greatest_common = max(greatest_common, common);
    }
  }
  
  cout << greatest_common + 1 << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
	return 0;
}
