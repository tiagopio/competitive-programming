#include <bits/stdc++.h>
using namespace std;

#define int long long

map<int, int> factor(int n) {
  map<int, int> ret;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n > 1) { ret[n]++; }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  map<int, int> mp = factor(n);
  vector<int> divs;
  for (auto i : mp) {
    int qtd = i.second, it = 1;
    while(qtd >= it) {
      divs.push_back((int)pow(i.first, it));
      qtd -= it;
      it++;
    }
  }
  sort(divs.begin(), divs.end());
  int id = 0, ans = 0;
  while(id < divs.size() and n >= divs[id]) {
    if (n % divs[id] == 0) n /= divs[id], ans++;
    id++;
  }
  cout << ans << '\n';
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

