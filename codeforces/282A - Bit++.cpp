// 232440055 	Nov/11/2023 20:11UTC-3 	tiagowhk 	A - Bit++ 	GNU C++17 	Accepted 	15 ms 	0 KB
#include <iostream>
using namespace std;

int main() {
  int n, x(0);
  cin >> n;
  if (n < 1 || n > 150) return 0;

  string str; 
  while (n--) {
    cin >> str;
    if (str[0] == '+' || str[2] == '+') x++;
    else x--;
  }

  cout << x << endl;

  return 0;
}
