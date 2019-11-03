/*
ID: varunra2
LANG: C++
TASK: hps
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


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("hps.in", "r", stdin);    
  freopen("hps.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n, k;

  cin >> n >> k;

  VI use(n);

  for(int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if(c == 'H') use[i] = 0;
    else if(c == 'P') use[i] = 1;
    else use[i] = 2;
  }

  vector<VVI> dp(n + 1, VVI(k + 1, VI(3, 0)));

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= k; j++) {
      for(int play = 0; play < 3; play++) {
        if(i == 0) {
          continue;
        }
        if(j == 0) {
          dp[i][j][play] = dp[i - 1][j][play] + (use[i - 1] == play ? 1 : 0);
        }
        else {
          int p1, p2;
          p1 = (play + 1)%3;
          p2 = (play + 2)%3;
          dp[i][j][play] = max(max(dp[i - 1][j][play], dp[i - 1][j - 1][p1]), dp[i - 1][j - 1][p2]) + (use[i - 1] == play ? 1 : 0);
        }
      }
    }
  }

  cout << max(max(dp[n][k][0], dp[n][k][1]), dp[n][k][2]) << endl;

  return 0;
}
