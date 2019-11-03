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

  vector<pair<ll, ll>> pos(n);
  vector<ll> c(n);
  vector<ll> k(n);

  for(int i = 0; i < n; i++) {
    cin >> pos[i].x >> pos[i].y;
  }
  for(int i  = 0; i < n; i++) {
    cin >> c[i];
  }
  for(int i  = 0; i < n; i++) {
    cin >> k[i];
  }

  ll ret = 0;

  VI pp;
  VII conn;

  vector<bool> vis(n, false);
  VI par(n, -1);

  for(int asdf = n; asdf--;) {
    int mn = INF + 10;
    int u = -1;
    for(int i = 0; i < n; i++) {
      if(vis[i]) continue;
      if(c[i] < mn) {
        mn = c[i];
        u = i;
      }
    }

    ret += mn;
    vis[u] = true;
    if(par[u] == -1) {
      pp.PB(u);
    }
    else {
      conn.PB(MP(min(par[u], u), max(par[u], u)));
    }

    for(int i = 0; i < n; i++) {
      ll cost = abs(pos[u].x - pos[i].x) + abs(pos[u].y - pos[i].y);
      cost *= (k[i] + k[u]);
      if(cost < c[i]) {
        c[i] = cost;
        par[i] = u;
      }
    }
  }

  cout << ret << endl;
  cout << pp.size() << endl;
  sort(pp.begin(), pp.end());

  for(int i = 0; i < pp.size(); i++) {
    cout << pp[i] + 1 << " ";
  }
  cout << endl;

  cout << conn.size() << endl;
  for(int i  =0; i < conn.size(); i++) {
    cout << conn[i].x + 1 << " " << conn[i].y + 1 << endl;
  }

  return 0;
}
