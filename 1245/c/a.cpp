/*
ID: varunra2
LANG: C++
TASK: c
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
  freopen("c.in", "r", stdin);    
  freopen("c.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();
  vector<ll> gps;
  ll ucount = 0;
  
  for(int i = 0; i < n; i++) {
    if(s[i] == 'u') ucount++;
    else if(ucount > 0) {gps.PB(ucount);ucount = 0;}
    if(s[i] == 'w' or s[i] == 'm') {
      cout << 0 << endl;
      return 0;
    }
  }
  if(ucount > 0) gps.PB(ucount);

  ll ncount = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'n') ncount++;
    else if(ncount > 0) {gps.PB(ncount); ncount = 0;}
  }
  if(ncount > 0) gps.PB(ncount);

  vector<ll> fib(n + 3);
  fib[0] = 1;
  fib[1] = 1;
  for(int i = 2; i < fib.size(); i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    fib[i] %= MOD;
  }
  ll ret = 1;
  for(int i = 0; i < gps.size(); i++) {
    ret *= fib[gps[i]];
    ret %= MOD;
  }
  

  cout << ret << endl;
  
  return 0;
}
