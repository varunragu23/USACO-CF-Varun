/*
ID: varunra2
LANG: C++
TASK: radio
*/
#pragma region Headers, define, typedef
#include<bits/stdc++.h>

using namespace std;
#ifdef DEBUG
#include <debug.h>
#endif

#define EPS 1e-9
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define x first
#define y second

const double PI = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// util functions

#pragma endregion

  int n, m;

ll dist(VI& a, VI& b) {
  ll dx, dy;
  dx = abs(a[0] - b[0]);
  dy = abs(a[1] - b[1]);
  return dx*dx + dy*dy;
}

ll solve(int x, int y, VVI& dp, VVI& a, VVI& b) {
  if(dp[x][y] != -1) return dp[x][y];
  
  dp[x][y] = dist(a[x], b[y]);
  if(x == n and y == m) return dp[x][y];
  ll ret = 1e18;

  if(x < n) {
    ret = min(ret, solve(x + 1, y, dp, a, b));
  }
  if(y < m) {
    ret = min(ret, solve(x, y + 1, dp, a, b));
  }
  if(x < n and y < m) {
    ret = min(ret, solve(x + 1, y + 1, dp, a, b));
  }

  dp[x][y] += ret;

  return dp[x][y];
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("radio.in", "r", stdin);    
  freopen("radio.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int X1, Y1, X2, Y2;
  string s, t;


  cin >> n >> m;

  cin >> X1 >> Y1 >> X2 >> Y2;

  cin >> s >> t;

  VVI dp(n + 1, VI(m + 1, -1));

  VVI a(n + 1, VI(2, 0)), b(m + 1, VI(2, 0));

  a[0][0] = X1;
  a[0][1] = Y1;

  b[0][0] = X2;
  b[0][1] = Y2;

  for(int i = 1; i <= n; i++) {
    char c = s[i - 1];
    if(c == 'N') {
      a[i][1]++;
    }
    else if(c == 'S') {
      a[i][1]--;
    }
    else if(c == 'W') {
      a[i][0]--;
    }
    else {
      a[i][0]++;
    } 
    a[i][0] += a[i - 1][0];
    a[i][1] += a[i - 1][1];
  }

  for(int i = 1; i <= m; i++) {
    char c = t[i - 1];
    if(c == 'N') {
      b[i][1]++;
    }
    else if(c == 'S') {
      b[i][1]--;
    }
    else if(c == 'W') {
      b[i][0]--;
    }
    else {
      b[i][0]++;
    } 
    b[i][0] += b[i - 1][0];
    b[i][1] += b[i - 1][1];
  }



  cout << solve(0, 0, dp, a, b) - dist(a[0], b[0]) << endl;

  

  

  return 0;
}
