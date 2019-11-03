#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define fi first
#define sc second
#define ALL(x) x.begin(), x.end()
#define RALL(X) x.begin(), x.end()
#define FOR(i, n, k) for(i=0; i<n; i+=k)
#define FO(i, n, k) for(i=1; i<=n; i+=k)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define N 100005
#define mid ((l+r)/2)
#define dbg(x) (cerr << #x << " : " << x << endl)
#define endl "\n"
#define MOD 100000009
 
using namespace std;
 
typedef long long lli;
#define int long long
 
signed main(){
  ios_base::sync_with_stdio(false);
  int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;	
  cin >>  x1 >> y1 >> x2 >>  y2;
  cin >> x3 >>  y3 >>  x4 >>  y4;
  cin >>  x5 >> y5 >> x6 >>  y6;
 
  int area = (x2-x1) * (y2-y1);
 
  int area2 = (min(x4, x2) - max(x1, x3)) * (min(y2, y4) - max(y3, y1));
  if(area2 > 0)
    area -= area2;
 
  int area3 = (min(x2, x6) - max(x1, x5)) * (min(y2, y6) - max(y5, y1));
  if(area3 > 0) 
    area -= area3;		
 
  int area4 = (min({x2, x4, x6}) - max({x1, x3, x5})) * (min({y2, y4, y6}) - max({y1, y3, y5}));
  if(area4 > 0)
    area += area4;
 
  if(area > 0){
    cout << "YES";
  }else cout << "NO";
  
for (int cnt = 0; cnt < maximum; cnt++)
{
  fas;dfjas;dlfjkas
}
if (i<2)
{
  somethig;
}
else
{
  else;
}

if (/* condition */)
{
  /* code */
}
else if (/* condition */)
{
  /* code */
}
else
{
  /* code */
}
while (/* condition */)
{
  /* code */
}
switch (expression)
{
case /* constant-expression */:
  /* code */
  break;

default:
  break;
}
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int s = 0){
    visited[s] = true;
    for(auto &i: adj[s])dfs(i);
}






  return 0;
}