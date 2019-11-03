/*
ID: varunra2
LANG: C++
TASK: nocross
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
  freopen("nocross.in", "r", stdin);    
  freopen("nocross.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  VI a(n), b(n);

  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }

  VVI dp(n, VI(n, 0));

  dp[0][0] = abs(a[0] - b[0]) <= 4;

  for(int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i - 1][0], (int) (abs(a[i] - b[0]) <= 4));
    dp[0][i] = max(dp[0][i - 1], (int) (abs(a[0] - b[i]) <= 4));
  }

  for(int i = 1; i < n; i++) {
    for(int j = 1; j < n; j++) {
      dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (int) (abs(a[i] - b[j]) <= 4));
    }
  }

  cout << dp[n - 1][n - 1] << endl;

  return 0;
}
