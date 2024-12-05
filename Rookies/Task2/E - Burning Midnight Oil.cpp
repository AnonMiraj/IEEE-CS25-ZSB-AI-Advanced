// ﷽
// Contest: Codeforces Round 112 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/165/problem/B
// Memory Limit: 256
// Time Limit: 2000
// Start: Mon 05 Feb 2024 07:31:05 PM UTC
//
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
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
#define int long long
using namespace std;

void solve() {
  int n, k, v;
  cin >> n >> k;
  int l = 0, r = n;
  int sum;
  while (l < r) {
    int m = v = (l + r) / 2;
    for (sum = 0; v; v /= k) {
      sum += v;
    }
    if (sum < n) {
      l = m + 1;
    } else {
      r = m;
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
