/*
ID: varunra2
LANG: C++
TASK: lightsout
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
  freopen("lightsout.in", "r", stdin);    
  freopen("lightsout.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  vector<pair<ll, ll>> vals(n);

  for(int i = 0; i < n; i++) {
    cin >> vals[i].x >> vals[i].y;
  }

  VI s;
  s.PB(0);

  for(int i = 0; i < n; i++) {
    int p1, p2;
    p1 = i + 1;
    p2 = i + 2;
    p1 %= n;
    p2 %= n;
    int dist = abs(vals[i].x - vals[p1].x) + abs(vals[i].y - vals[p1].y);
    s.PB(dist);
    if((vals[i].x - vals[p1].x) * (vals[p2].y - vals[p1].y) > (vals[p2].x - vals[p1].x)*(vals[i].y - vals[p1].y)) {
      s.PB(-1);
    }
    else s.PB(-2);
  }

  s.back() = 0;

  VI op(n + 1, 0);

  for(int i = 0; i < n; i++) {
    op[i + 1] = op[i] + s[2*i + 1];
  }

  op[n] = 0;

  for(int i = n - 1; i >= 0; i--) {
    op[i] = min(op[i], op[i + 1] + s[2*i + 1]);
  }

  multiset<VI> mst;

  //not minimum spanning tree :)

  for(int i = 0; i < s.size(); i += 2) {
    for(int l = 1; i + l <= s.size(); l += 2) {
      mst.insert(VI(s.begin(), s.begin() + i + l));
    }
  }

  int ret = 0;

  for(int i = 2; i + 2 < s.size(); i += 2) {
    int l;
    int cst;
    cst = 0;
    for(l = 1;i + l < s.size(); l += 2) {
      if(mst.count(VI(s.begin() + i, s.begin() + i + l)) == 1) {
        break;
      }
      
      cst += s[i + l];
    }
    ret = max(ret, cst + op[(i + l)/2] - op[i/2]);
  }

  cout << ret << endl;

  return 0;
}
