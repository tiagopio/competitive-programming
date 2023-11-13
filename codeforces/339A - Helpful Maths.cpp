// 232688856 	Nov/13/2023 20:38UTC-3 	tiagowhk 	339A - Helpful Maths 	GNU C++17 	Accepted 	30 ms 	0 KB
#include <iostream>
using namespace std;

void bubble(string &s) {
  int n = s.length();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (s[j] == '+' && s[j + 1] != '+') {
        char tmp = s[j];
        s[j] = s[j + 1];
        s[j + 1] = tmp;
      } else if (s[j] > s[j + 1]) {
        char tmp = s[j];
        s[j] = s[j + 1];
        s[j + 1] = tmp;
      }
    }
  }
}

int main() {
  string s;
  cin >> s;
  bubble(s);
  cout << s << endl;
  return 0;
}
