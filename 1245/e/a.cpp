/*
ID: varunra2
LANG: C++
TASK: e
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

int conv(int i, int j) {
  return i*10 + j;
}
int g(int i, int r) {
  if(i + r > 100) return i;
  return i + r;
}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("e.in", "r", stdin);    
  freopen("e.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  VVI grid(10, VI(10));

  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      cin >> grid[i][j];
    }
  }

  VI arr(101);

  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      int u = conv(i, j);
      u++;
      int v = u + 10*grid[i][j];
      arr[u] = v;
    }
  }

  vector<ld> dp(101, 0);
  dp[100] = 1.0;

  for(int i = 99; i >= 95; i--) {
    for(int j = 1; j <= 100 - i; j++) {
      dp[i] += ((ld)1/6 * min(dp[i + j], dp[arr[i + j]]));
    }
    dp[i] += (1.0000);
    dp[i] *= (ld)(6/(100 - i));
  }
  for(int i = 94; i >= 1; i--) {
    for(int j = 1; j <= 6; j++) {
      dp[i] += ((ld)1/6*min(dp[i + j], dp[arr[i + j]]));
    }
    dp[i] += 1.0000;
  }

  cout << setprecision(15) << dp[1] << endl;

  return 0;
}
