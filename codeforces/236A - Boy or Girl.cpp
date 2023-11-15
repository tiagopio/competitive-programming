// 232803120 	Nov/14/2023 21:17UTC-3 	tiagowhk 	236A - Boy or Girl 	GNU C++17 	Accepted 	30 ms 	100 KB
#include <iostream>
#include <set>
using namespace std;

int main()
{
  string s, n;
  set<char> u;

  cin >> s;
  
  for (char c: s) {
    u.insert(c);
  }

  for (char c: u) {
    n += c;
  }
  
  n.length() % 2 == 0 ? cout << "CHAT WITH HER!" << endl : cout << "IGNORE HIM!" << endl;;
  
  return 0;
}
