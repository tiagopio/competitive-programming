// 232688236 	Nov/13/2023 20:16UTC-3 	tiagowhk 	A - Petya and Strings 	GNU C++17 	Accepted 	30 ms 	0 KB
#include <cctype>
#include <iostream>
using namespace std;

int main() {
  
  string f, s; 
  cin >> f >> s;
  
  for (int i = 0; i < f.length(); i++) {
    f[i] = tolower(f[i]);
    s[i] = tolower(s[i]);
  }
  
  if (f < s) {
    cout << -1 << endl;
  }
  if (s < f) {
    cout << 1 << endl;
  }
  if (f == s) {
    cout << 0 << endl;
  }
  return 0;
}
