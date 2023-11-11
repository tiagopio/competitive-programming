// 232307882 	Nov/10/2023 21:12UTC-3 	tiagowhk 	A - Team 	GNU C++17 	Accepted 	30 ms 	0 KB
#include <iostream>
using namespace std;

int main() {
  int n, p, v, t, number(0);
  cin >> n;
  
  while (n--) {
    cin >> p >> v >> t;

    if (p + v + t >= 2) {
      number += 1;
    }
  }

  cout << number << endl;

  return 0;
}
