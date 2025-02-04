#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

void solve() {
  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);

  int n; cin >> n; cin.ignore();

  sort(cows.begin(), cows.end());
  vector<pair<string, string>> cons(n);
  for (int i = 0; i < n; i++) {
    string s;
    getline(cin, s);

    vector<string> words;
    stringstream ss(s);
    string word;

    while(ss >> word) words.push_back(word);
    cons[i] = {words[0], words[words.size() - 1]};
  }

  do {
    auto check = [&](int j) {
      return j >= 0 and j < cows.size();
    };
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < cows.size(); j++) {
        if (cows[j] == cons[i].first) {
          bool before = false, after = false;
          if (check(j - 1)) {
            if (cows[j - 1] == cons[i].second) before = true;
          }
          if (check(j + 1)) {
            if (cows[j + 1] == cons[i].second) after = true;
          }
          ok &= (before or after);
        }
      }
    }
    if (ok) {
      for (auto i : cows) cout << i << '\n';
      return;
    }

  } while(next_permutation(cows.begin(), cows.end()));
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
