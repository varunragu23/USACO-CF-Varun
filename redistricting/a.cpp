/*
ID: varunra2
LANG: C++
TASK: redistricting
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
  freopen("redistricting.in", "r", stdin);    
  freopen("redistricting.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  VI dp(300001, 0);
  VI pref(300001, 0);

  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'H') {
      pref[i + 1] = pref[i] + 1;
    }
    else pref[i + 1] = pref[i] - 1;
  }

  multiset<int> dpv;
  dpv.insert(0);

  multiset<int> elem[300001];

  elem[0].insert(0);

  for (int i = 1; i <= n; i++){
      int mnval = *(dpv.begin());
      if (*elem[mnval].begin() < pref[i]){
        dp[i] = mnval;
      }
      else{
        dp[i] = mnval + 1;
      }
      dpv.insert(dp[i]);
      elem[dp[i]].insert(pref[i]);
      
      if (i >= k){
        dpv.erase(dpv.find(dp[i - k]));
        elem[dp[i - k]].erase(elem[dp[i - k]].find(pref[i - k]));
      }
    }

  cout << dp[n] << endl;

  return 0;
}
