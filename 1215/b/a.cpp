/*
ID: varunra2
LANG: C++
TASK: b
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

#define deb(x) cerr << #x << " = " << x << endl;

// util functions

#pragma endregion


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("b.in", "r", stdin);    
  freopen("b.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


    ll n;
    cin >> n;

    vector<ll> vals(n);

    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if(x > 0) {
        vals[i] = 1;
      }
      else vals[i] = -1;
    }

  vector<pair<ll, ll>> dp(n);

  dp[n - 1].x = (vals[n - 1] == 1);
  dp[n - 1].y = 1 - dp[n - 1].x;

  for(int i = n - 2; i >= 0; i--) {
    if(vals[i] == 1) {
      dp[i].x = dp[i + 1].x + 1;
      dp[i].y = dp[i + 1].y;
    }
    else {
      dp[i].x = dp[i + 1].y;
      dp[i].y = dp[i + 1].x + 1;
    }
  }  

  ll neg = 0;
  ll pos = 0;

  for(int i = 0; i < n; i++) {
    neg += dp[i].y;
    pos += dp[i].x;
  } 

  cout << neg << " " << pos << endl;

  return 0;
}
