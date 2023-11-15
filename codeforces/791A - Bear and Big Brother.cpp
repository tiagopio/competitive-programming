// 232910210 	Nov/15/2023 20:28UTC-3 	tiagowhk 	791A - Bear and Big Brother 	GNU C++17 	Accepted 	15 ms 	0 KB
#include <iostream>
#include <set>
using namespace std;

int main()
{
  int a, b, y = 0;

  cin >> a >> b;
  if (a < 1 || a > 10 || b < 1 || b > 10) return 0;

  while (a <= b) {
    a *= 3;
    b *= 2;
    y++;
  }
  
  cout << y << endl;

  return 0;
}
