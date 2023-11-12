// 232562564 	Nov/12/2023 19:42UTC-3 	tiagowhk 	263A - Beautiful Matrix 	GNU C++17 	Accepted 	30 ms 	0 KB
#include <iostream>
#include <cstdlib>
#define SIZE 5
using namespace std;

int main() {

  int m[SIZE][SIZE], r, c, mov = 0;
  
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      cin >> m[i][j];
      if (m[i][j] == 1) {
        r = i + 1;
        c = j + 1;
      }
    }
  } 

  cout << abs(3 - r) + abs(3 - c) << endl;

  return 0;
}
