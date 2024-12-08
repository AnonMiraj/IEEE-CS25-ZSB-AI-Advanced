

#include <algorithm>
#include <bitset>
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
#define ll long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (auto &i : arr)
    cin >> i;
  sort(arr, arr + n);
  int p1 = 0, p2 = 0, ans=0;
  while(p2!=n) {
    int temp;
    if (arr[p2] - arr[p1] <= 5) {
      temp=p2-p1;
      ans=max(ans,temp);
      p2++;
    }
    else {
      p1++;
    }
  }
  cout<<ans+1;
}

int main() {

  //  freopen("whereami.in", "r", stdin);
  //  freopen("whereami.out", "w", stdout);
  fastio();
  int n = 1;
  // cin >> n;
  while (n--)
    solve();
  return 0;
}

