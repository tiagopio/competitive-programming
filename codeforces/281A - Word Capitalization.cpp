// 232802692 	Nov/14/2023 21:00UTC-3 	tiagowhk 	A - Word Capitalization 	GNU C++17 	Accepted 	30 ms 	0 KB
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
  string s;
  
  cin >> s;
  
  char ch = toupper(s[0]);
  s[0] = ch;
  
  cout << s << endl;

  return 0;
}
