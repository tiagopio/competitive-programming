// 233593956 	Nov/20/2023 13:21UTC-3 	tiagowhk 	A - String Task 	GNU C++20 (64) 	Accepted 	30 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

void solve() {
  string s;
  cin >> s;
  vector<pair<char, char>> vec;
	
  for (int i = 0; i < s.length(); i++) {
    s[i] = tolower(s[i]);
  }
	
  for (int i = 0; i < s.length(); i++) {
	if (s[i] != 'y' && s[i] != 'a' && s[i] != 'e'&& s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
	  vec.pb({'.', s[i]});
	}
  }
	
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i].first << vec[i].second;
  }
		
  cout << endl;
}

int main() {
  solve();
  return 0;
}
