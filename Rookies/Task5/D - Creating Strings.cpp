// ﷽
// Contest: Rescursion
//
// Judge: Virtual Judge
// URL: https://vjudge.net/contest/670435#problem/D
// Memory Limit: 512
// Time Limit: 1000
// Start: Fri 13 Dec 2024 04:25:57 PM EET
// Reading Time :
// Thinking Time :
// Coding Time :
// Debug Time :
// Submit Count :
// Problem Level :
// Category :
// Comments :
#include <bits/stdc++.h>

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
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

/*template <class T> using rpq = priority_queue<T, vector<T>, greater<T>>;*/

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1},
          dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

using namespace std;


void solve() {
  string s;
  cin >> s;
  int n = s.size();
  sort(all(s));
  vector<int> fact = {1};
  for (int i = 2; i <= 8; i++) {
    fact.push_back(fact.back() * i);
  }

  int ans = 1;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      cnt = 1;
    }
    if (s[i] == s[i - 1])
      cnt += 1;
    ans *= cnt;
  }
  debug(fact);
  cout << fact[n - 1] / ans << "\n";
  do {
    cout << s << "\n";
  } while (next_permutation(all(s)));
}
int32_t main() {
  /*freopen("whereami.in", "r", stdin);*/
  /*freopen("whereami.out", "w", stdout);*/
  fastio();
  int n = 1;

#ifdef MUTLI_CASE
  cin >> n;
#endif
  while (n--)
    solve();
  return 0;
}
