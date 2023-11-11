// 232306864 	Nov/10/2023 20:38UTC-3 	tiagowhk 	A - Way Too Long Words 	GNU C++17 	Accepted 	15 ms 	0 KB 
#include <iostream>
using namespace std;

int main() { 
  int n;
  cin >> n;
  if (n < 1 || n > 100) return 0;

  while (n--) {
    string str;
    cin >> str;

    if (str.length() > 10) { 
      cout << str[0] << str.length() - 2 << str[str.length() - 1] << endl; 
    } else {
      cout << str << endl;
    }

  }

  return 0;
}
