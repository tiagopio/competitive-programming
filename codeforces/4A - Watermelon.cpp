// 232166502 	Nov/09/2023 22:21UTC-3 	tiagowhk 	A - Watermelon 	GNU C++17 	Accepted 	30 ms 	0 KB
#include <iostream>
using namespace std;
     
  int main() {
  int w;
      
  cin >> w;
  if (w < 1 || w > 100) return 0;
      
  cout << ((w % 2 == 0 && w > 2) ? "YES" : "NO") << endl;
      
  return 0;
}
