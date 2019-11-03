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

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// util functions

#pragma endregion


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("b.in", "r", stdin);    
  freopen("b.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int h, w;
  cin >> h >> w;

  VI r(h);
  VI c(w);

  for(int i = 0; i < h; i++) {
    cin >> r[i];
  }
  
  for(int i = 0; i < w; i++) {
    cin >> c[i];
  }

  //VVI grid(h, VI(w, 0));

for(int i = 0; i < h; i++) {
    if(r[i] == w) continue;
    if(c[r[i]] > i) {
      cout << 0 << endl;
      return 0;
    }
  }

  for(int i = 0; i < w; i++) {
    if(c[i] == h) continue;
    if(r[c[i]] > i) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ret = 1;

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(j > r[i] and i > c[j]) {
        ret *= 2;
        ret %= MOD;
      }
    }
  }

  cout << ret << endl;


  return 0;
}
