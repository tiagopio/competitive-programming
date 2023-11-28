// 234755506 	Nov/28/2023 09:59UTC-3 	tiagowhk 	A - Lucky Division 	GNU C++20 (64) 	Accepted 	30 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n;
  cin >> n;
  vector<ll> vec;
  int tmp = n;  
  while (n > 0) {
    vec.pb(n % 10);
    n /= 10;
  } 
  
  reverse(vec.begin(), vec.end());
  
  int c = 0;
  if (tmp % 4 == 0 || tmp % 7 == 0 || tmp % 44 == 0 || tmp % 47 == 0 || tmp % 74 == 0 || tmp % 77 == 0 || tmp % 444 == 0 || tmp % 447 == 0 || tmp % 474 == 0 || tmp % 744 == 0 || tmp % 477 == 0 || tmp % 747 == 0 || tmp % 774 == 0 || tmp % 777 == 0) {
    cout << "YES" << endl;
  } else {
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] != 4 && vec[i] != 7) {
        c++;
      }
    }
      if (c) {
	cout << "NO\n";
       } else {
	cout << "YES\n";
       }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
} 
