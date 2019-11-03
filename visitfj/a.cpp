/*
ID: varunra2
LANG: C++
TASK: visitfj
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
  freopen("visitfj.in", "r", stdin);    
  freopen("visitfj.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  VI dr = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
  VI dc = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};

  int n, t;
  cin >> n >> t;

  VVI vals(n, VI(n));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> vals[i][j];
    }
  }

  vector<vector<ll>> dist(n, vector<ll>(n, LONG_MAX));

  dist[0][0] = 0;

  priority_queue<pair<ll, ll>> q;

  q.push(MP(0, 0));

  ll ret = LONG_MAX;

  while(!q.empty()) {
    ll d = -q.top().x;
    int r, c;
    r = q.top().y / n;
    c = q.top().y % n;
    q.pop();

    if(d != dist[r][c]) {
      continue;
    }

    ll di; // dist from n - 1, n - 1;

    di = abs(n - 1 - r) + abs(n - 1 - c);

    if(di <= 2) {
      ret = min(ret, d + di * t);
    }

    for(int i = 0; i < dr.size(); i++) {
      int nr, nc;
      nr = r + dr[i];
      nc = c + dc[i];
      if(nr < 0 or nc < 0 or nr >= n or nc >= n or dist[nr][nc] < d + vals[nr][nc] + 3*t) {
        continue;
      }
      dist[nr][nc] = d + vals[nr][nc] + 3*t;
      q.push(MP(-dist[nr][nc], nr*n + nc));
    }
  }

  cout << ret << endl;


  return 0;
}
