// ﷽
// Contest: Codeforces Round 321 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/580/C
// Memory Limit: 256
// Time Limit: 2000
// Start: Sat 24 Aug 2024 08:46:37 PM EEST
// Reading Time : 3
// Thinking Time : 5
// Coding Time : 
// Comments : 
#include<bits/stdc++.h>

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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using namespace std;

void solve() {
  int n;
  int m;
  cin >> n;
  cin >> m;
  vector<int> a(n+1);
  vector<int> vis(n+1);
  for (int i = 1; i <=n; i++) {
      cin >> a[i];
  }
  vector<int> adj[n+1];

  int x,y;
  for (int i = 1; i < n; i++) {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
  }
  debug(a);
  int ans=0;
  function<void(int,int)> dfs = [&](int p,int c){
    vis[p]=1;
    debug(c);
      if(c>m)
        return;
      if(p!=1)
        ans+=(adj[p].size()==1);
    for(auto v:adj[p])
    {
      if(!vis[v])
        dfs(v,(a[p]*a[v])*(c)+a[v]);
    }
  };

  debug(a);
  dfs(1,a[1]);
  cout<<ans;
}
int32_t main() {

  /*freopen("whereami.in", "r", stdin);*/
  /*freopen("whereami.out", "w", stdout);*/
  fastio();
  int n = 1;
  /*cin>>n;*/
  while (n--)
    solve();
  return 0;
}
