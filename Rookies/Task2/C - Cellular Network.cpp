// ﷽
// Contest: Educational Codeforces Round 15
// Judge: Codeforces
// URL: https://codeforces.com/contest/702/problem/C
// Memory Limit: 256
// Time Limit: 3000
// Start: Fri 05 Apr 2024 10:02:56 PM EET
// Reading Time :
// Thinking Time :
// Coding Time :
// Comments :
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#ifdef ALGOAT
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
#define int long long
using namespace std;
int n, m;

vector<int> fre;
bool testr(int *nrr, int *mrr, int r) {

  for (int i = 0, cnt = 0; i < n;) {
    if ((nrr[i] >= mrr[cnt] && nrr[i] <= mrr[cnt] + r) ||
        (nrr[i] <= mrr[cnt] && nrr[i] >= mrr[cnt] - r))
      i++;
    else
      cnt++;
    if (cnt == m)
      return 1;
  }

  return 0;
}

void solve() {
  cin >> n >> m;
  int nrr[n], mrr[m];
  fre = vector<int>(n);
  for (auto &i : nrr) {
    cin >> i;
  }
  for (auto &i : mrr) {
    cin >> i;
  }
  debug_itr(nrr, nrr + n);
  debug_itr(mrr, mrr + m);
  int l = 0, r = INT_MAX;
  while (l < r) {
    int mid = (l + r) / 2;
    if (testr(nrr, mrr, mid)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << l;
}
int32_t main() {

  //  freopen("whereami.in", "r", stdin);
  //  freopen("whereami.out", "w", stdout);
  fastio();
  int n = 1;
  // cin>>n;
  while (n--)
    solve();
  return 0;
}
