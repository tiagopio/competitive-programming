#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<string> a(3);

set<pair<char, char>> teams;
set<char> solo;

int check(int qtd) {
  int total = 0;

  for (int i = 0; i < 3; i++) {
    set<char> row, col;
    for (int j = 0; j < 3; j++) row.insert(a[i][j]);
    for (int j = 0; j < 3; j++) col.insert(a[j][i]);
    if (row.size() == qtd) {
      if (qtd == 1) {
        char tmp = *row.begin();
        if (!solo.count(tmp)) total++;
        solo.insert(tmp);
      } else {
        char tmp1, tmp2;
        tmp1 = *row.begin();
        row.erase(tmp1);
        tmp2 = *row.begin();
        pair<char, char> ptmp = make_pair(tmp1, tmp2);
        if (!teams.count(ptmp)) total++;
        teams.insert(ptmp);
      }
    }
    if (col.size() == qtd) {
      if (qtd == 1) {
        char tmp = *col.begin();
        if (!solo.count(tmp)) total++;
        solo.insert(tmp);
      } else {
        char tmp1, tmp2;
        tmp1 = *col.begin();
        col.erase(tmp1);
        tmp2 = *col.begin();
        pair<char, char> ptmp = make_pair(tmp1, tmp2);
        if (!teams.count(ptmp)) total++;
        teams.insert(ptmp);
      }
    } 
  }

  set<char> mn, sc;
  for (int i = 0; i < 3; i++) mn.insert(a[i][i]);
  sc.insert(a[2][0]), sc.insert(a[1][1]), sc.insert(a[0][2]);
  if (mn.size() == qtd) {
    if (qtd == 1) {
      char tmp = *mn.begin();
      if (!solo.count(tmp)) total++;
      solo.insert(tmp);
    } else {
      char tmp1, tmp2;
      tmp1 = *mn.begin();
      mn.erase(tmp1);
      tmp2 = *mn.begin();
      pair<char, char> ptmp = make_pair(tmp1, tmp2);
      if (!teams.count(ptmp)) total++;
      teams.insert(ptmp);
    }
  }
  if (sc.size() == qtd) {
    if (qtd == 1) {
      char tmp = *sc.begin();
      if (!solo.count(tmp)) total++;
      solo.insert(tmp);
    } else {
      char tmp1, tmp2;
      tmp1 = *sc.begin();
      sc.erase(tmp1);
      tmp2 = *sc.begin();
      pair<char, char> ptmp = make_pair(tmp1, tmp2);
      if (!teams.count(ptmp)) total++;
      teams.insert(ptmp);
    }
  }

  return total;
}

void solve() {
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);

  for (int i = 0; i < 3; i++) cin >> a[i];
  int one, two;
  one = two = 0;

  one += check(1);
  two += check(2);

  cout << one << '\n' << two << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
