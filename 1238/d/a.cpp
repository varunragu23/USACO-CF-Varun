/*
ID: varunra2
LANG: C++
TASK: d
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
  freopen("d.in", "r", stdin);    
  freopen("d.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  ll tot = n;
  tot *= (n + 1);
  tot /= 2;

  int aab = 0;
  int abb = 0;
  int ab = 0;
  
  
  VI dp(n);
  dp[0] = 1;
  
  for(int i = 1; i < n; i++) {
    if(s[i] == s[i - 1]) dp[i] = dp[i - 1] + 1;
    else dp[i] = 1;
  }

  VI g;
  for(int i = 1; i < n; i++) {
    if(dp[i] != dp[i - 1]) {
      g.PB(dp[i - 1]);
    }
  }

  g.PB(dp[n - 1]);

  for(int i = 0; i < g.size() - 1; i++) {
    aab += g[i];
  }

  for(int i = 1; i < g.size(); i++) {
    abb += g[i];
  }

  ab = g.size() - 1;

  cout << tot - aab - abb + ab << endl;

  return 0;
}
