// 232909720 	Nov/15/2023 20:10UTC-3 	tiagowhk 	A - Stones on the Table 	GNU C++17 	Accepted 	30 ms 	0 KB
#include <iostream>
#include <set>
using namespace std;

int main()
{
  string s;
  int n, r = 0, g = 0, b = 0;
  cin >> n;
  cin >> s;
    
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == s[i]) {
      if (s[i] == 'R') r++;
      else if (s[i] == 'G') g++;
      else if (s[i] == 'B') b++;
    }
  }
  
  cout << r + g + b << endl;
   
  return 0;
}
