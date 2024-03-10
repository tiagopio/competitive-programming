/*
  Task:	Palindrome Reorder
  Sender:	tiagopio
  Submission time:	2024-03-10 19:18:54 +0200
  Language:	C++20
  Status:	READY
  Result:	ACCEPTED
*/

#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef long double ld;
const int N = 1e4+10;
const int mod = 1e9+7;
const ll inf = 1e9+10;
 
void solve() {
  string s;
  cin >> s;
  int cnt[26] = {0};
  int bad = 0;
 
  for (int i = 0; i < (int)s.length(); i++) cnt[s[i] - 'A']++;
  for (int i = 0; i < 26; i++) if (cnt[i] % 2) bad++;
  
  if (bad > 1) {
    cout << "NO SOLUTION\n";
    return;
  }
 
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2 == 0) {
      for (int j = 0; j < cnt[i] / 2; j++) {
        char c = i + 'A';
        cout << c;
      }
    }
  }
  
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2) {
      for (int j = 0; j < cnt[i]; j++) {
        char c = i + 'A';
        cout << c;
      }
    }
  }
 
  for (int i = 25; i >= 0; i--) {
    if (cnt[i] % 2 == 0) {
      for (int j = 0; j < cnt[i] / 2; j++) {
        char c = i + 'A';
        cout << c;
      }
    }
  }
  cout << endl;
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
