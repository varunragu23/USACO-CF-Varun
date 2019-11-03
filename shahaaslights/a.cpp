/*
ID: varunra2
LANG: C++
TASK: shahaaslights
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
  freopen("shahaaslights.in", "r", stdin);    
  freopen("shahaaslights.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> ncr(n + 1, vector<ll>(n + 1, 1));
  vector<ll> s(m);
  vector<ll> pow(n + 1);

  ll ans = 1;

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 or j == i) {
        ncr[i][j] = 1;
      }
      else {
        ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        ncr[i][j] %= MOD;
      }
    }
  }

  pow[0] = 1;

  pow[1] = 1;

  for(int i = 2; i <= n; i++) {pow[i] = pow[i - 1]*2; pow[i] %= MOD;}
  for(int i = 0; i < m; i++) {cin >> s[i];}

  sort(s.begin(), s.end());

  ll cnt = 0, tmp;

  for(int i = 0; i < m; i++) {
    if(i == 0) tmp = s[i] - 1;
    else {
      tmp = s[i] - s[i - 1] - 1;
      ans *= pow[tmp];
      ans %= MOD;
    }
    cnt += tmp;
    
    ans *= ncr[cnt][tmp];
    ans %= MOD;
    
  }

  cnt += (n - s[m - 1]);
  ans *= ncr[cnt][n - s[m - 1]];
  ans %= MOD;

  cout << ans << endl;

  return 0;
}
