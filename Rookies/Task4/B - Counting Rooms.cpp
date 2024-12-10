// ﷽
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1192
// Memory Limit: 512
// Time Limit: 1000
// Start: Wed 03 Jul 2024 10:52:42 PM EEST
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

using namespace std;
int n,m;
vector<string>v;
int ans=0;
void dfs(int y,int x)
{
  if(x<0||y<0)
    return;
  if(x==m||y==n)
    return;
  if(v[y][x]=='#')
    return;
  v[y][x]='#';
  dfs(y+1,x);
  dfs(y-1,x);
  dfs(y,x+1);
  dfs(y,x-1);
}

void solve() {
  cin>>n>>m;
  string s;
  for(int i=0;i<n;i++)
  {
  cin>>s;
  v.push_back(s);
  }

  int ans=0;
  for(int i=0;i<n;i++)

  {
  for(int j=0;j<m;j++)
  {
    if(v[i][j]=='.')
    {
      ans++;
      dfs(i,j);
    }
  }
  }
  cout<<ans;


  

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

