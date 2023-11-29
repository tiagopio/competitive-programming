// 234985373 	Nov/29/2023 18:25UTC-3 	tiagowhk 	131A - cAPS lOCK 	GNU C++20 (64) 	Accepted 	15 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  string s;
  cin >> s;
  int m = 0;

  for (int i = 0; i < s.length(); i++) {
    if (isupper(s[i])){
      m++;
    }
  }

  if (m == s.length()) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }
  } else {
    if (islower(s[0])) {
      int c = 0;
      for (int i = 1; i < s.length(); i++) {
        if (isupper(s[i])) {
          c++;
        }
      }
      if (c == s.length() - 1) {
        s[0] = toupper(s[0]);
        for (int i = 1; i < s.length(); i++) {
          s[i] = tolower(s[i]);
        }
      }
    }
  }

  cout << s << endl;
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
