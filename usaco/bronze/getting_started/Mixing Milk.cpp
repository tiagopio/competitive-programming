#include <bits/stdc++.h>
using namespace std;

void solve() {
  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);
  
  vector<pair<long long, long long>> bucket(3);
  for (long long i = 0; i < 3; i++) {
    cin >> bucket[i].first >> bucket[i].second;
  }

  for (long long i = 0; i < 100; i++) {
    if (i % 3 == 0) {
      if (bucket[0].second + bucket[1].second <= bucket[1].first) {
        bucket[1].second += bucket[0].second;
        bucket[0].second = 0;
      } else {
        bucket[0].second -= bucket[1].first - bucket[1].second;
        bucket[1].second = bucket[1].first;
      }
    }
    if (i % 3 == 1) {
      if (bucket[1].second + bucket[2].second <= bucket[2].first) {
        bucket[2].second += bucket[1].second;
        bucket[1].second = 0;
      } else {
        bucket[1].second -= bucket[2].first - bucket[2].second;
        bucket[2].second = bucket[2].first;
      }
    }
    if (i % 3 == 2) {
      if (bucket[0].second + bucket[2].second <= bucket[0].first) {
        bucket[0].second += bucket[2].second;
        bucket[2].second = 0;
      } else {
        bucket[2].second -= bucket[0].first - bucket[0].second;
        bucket[0].second = bucket[0].first;
      }
    }
  }
  for (long long i = 0; i < 3; i++) {
    cout << bucket[i].second << '\n';
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