// 233029367 	Nov/16/2023 22:10UTC-3 	tiagowhk 	A - Elephant 	GNU C++17 	Accepted 	15 ms 	0 KB
#include <iostream>
using namespace std;

int main()
{
  int x, s = 0, sum = 0;
  cin >> x;
  if (x <= 0) return 0;
  
    for (int i = 5; i >= 1; i--) {
      if (sum + i <= x) {
        while (sum < x) {
          sum += i;
          s++;
        }
      }
    }
    
  cout << s << endl;
  
  return 0;
}
