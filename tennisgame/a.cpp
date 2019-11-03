/*
ID: varunra2
LANG: C++
TASK: tennisgame
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

map<PII, int> w;

int ok(int t, VI& vals) {

  int cur = 0;
  PII score;
  score = MP(0, 0);
  while(cur < vals.size()) {
    int p1 = 
  }

}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("tennisgame.in", "r", stdin);    
  freopen("tennisgame.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  VI vals(n);

  for(int i = 0; i < n; i++) {
    cin >> vals[i];
  }

  VII ret;

  VII pref(n, MP(0, 0));
  pref[0].x = vals[0] == 1;
  pref[0].y = 1 - pref[0].x;
  for(int i = 1; i < n; i++) {
    pref[i] = pref[i - 1];
    if(vals[i] == 1) pref[i].x++;
    else pref[i].y++;
  }

  for(int i = 0; i < n; i++) {
    w[pref[i]] = i;
  }

  for(int i = 0; i < n; i++) {
    int t = i;
    int s = ok(i, vals);
    if(s == -1) continue;
    ret.PB(MP(s, t));
  }

  return 0;
}
