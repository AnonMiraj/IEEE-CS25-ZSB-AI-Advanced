// ﷽
// Contest: BFS: Breadth First Search
//
// Judge: Virtual Judge
// URL: https://vjudge.net/contest/667555#problem/A
// Memory Limit: 1536
// Time Limit: 1000
// Start: Tue 10 Dec 2024 07:00:04 PM EET
// Reading Time :
// Thinking Time :
// Coding Time :
// Debug Time :
// Submit Count :
// Problem Level :
// Category :
// Comments : man this sol is very clean
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

using namespace std;

#define MUTLI_CASE

void solve() {

  int n = 8, m = 8;
  string st, en;
  cin >> st >> en;

  int stX = st[0] - 'a';
  int stY = st[1] - '1';

  int enX = en[0] - 'a';
  int enY = en[1] - '1';

  queue<pair<int, int>> q;
  vector<vector<int>> d(m, vector<int>(n, 0));
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  q.push({stX, stY});
  visited[stX][stY] = true;

  int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1},
      dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 8; ++i) {
      int newX = x + dx[i];
      int newY = y + dy[i];
      if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
          !visited[newX][newY]) {
        visited[newX][newY] = true;
        d[newX][newY] = d[x][y] + 1;
        q.push({newX, newY});
      }
    }
  }
  cout << d[enX][enY] << "\n";
  debug(st, en);
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
