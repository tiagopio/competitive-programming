// 232440369 	Nov/11/2023 20:23UTC-3 	tiagowhk 	50A - Domino piling 	GNU C++17 	Accepted 	30 ms 	0 KB
#include <iostream>
#define AREA 2
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  if (m < 1 || m > 16 || n < 1 || m > 16) return 0;

  int a = m * n;
  cout << a / AREA << endl;

  return 0;
}
