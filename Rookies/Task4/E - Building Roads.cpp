// ﷽
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1666
// Memory Limit: 512
// Time Limit: 1000
// Start: Sat 24 Aug 2024 08:03:28 PM EEST
// Reading Time : 
// Thinking Time : 
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
  int n,m;
  cin>>n>>m;
  vector<int> adj[n+1];
  vector<int> vis(n+1);
  vector<pair<int,int>> ans;
  int a,b;

  while(m--)
  {
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  debug_itr(adj,adj+n+1);
  function<void(int)> dfs = [&](int p){
    vis[p]=1;
    for(auto v:adj[p])
    {
      if(!vis[v])
        dfs(v);
    }
  };
  dfs(1);
  for(int i=2;i<=n;i++)
  {
    if(!vis[i])
    {
      dfs(i);
      ans.push_back({1,i});
    }

  }

  debug(vis);
      cout<<ans.size()<<"\n";
    for(auto [a,b]:ans)
      cout<<a<<" " <<b<<"\n";
      


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

