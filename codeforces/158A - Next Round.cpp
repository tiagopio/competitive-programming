// 232308784 	Nov/10/2023 21:40UTC-3 	tiagowhk 	A - Next Round 	GNU C++17 	Accepted 	30 ms 	0 KB
#include <iostream>
using namespace std;

int main() {
  int n, k, c(0), arr[50];
  
  cin >> n >> k;
  if (n < 1 || n > 50 || k < 1 || k > 50) return 0;
  
  for (int i = 0; i < n; i++) cin >> arr[i]; 
  
  int p = arr[k - 1];
  for (int i = 0; i < n; i++) if (arr[i] >= p && arr[i] != 0) c++;

  cout << c << endl;

  return 0;
}
