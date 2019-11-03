/*
ID: varunra2
LANG: C++
TASK: promote
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

struct BIT {
  VI leaf;
  public:
    void setter(int s) {
      leaf.resize(s + 5);
    }
    void inc(int x) {
      x += 2;
      while(x < leaf.size()) {
        leaf[x]++;
        x += (x & -x);
      }
    }
    int qry(int x) {
      int ret = 0;
      x += 2;
      while(x > 0) {
        ret += leaf[x];
        x -= (x & -x);
      }
      return ret;
    }
};
int el = 0;
void dfs(int cur, VI& start, VI& sz, VVI& adj) {
  start[cur] = el++;
  sz[cur]++;
  for(auto& x: adj[cur]) {
    dfs(x, start, sz, adj);
    sz[cur] += sz[x];
  }
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("promote.in", "r", stdin);    
  freopen("promote.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  VVI children(n);

  VI sz(n, 0);
  VI start(n, 0);

  VII ls(n);

  for(int i = 0; i < n; i++) {
    cin >> ls[i].x;
    ls[i].y = i;
  }

  sort(ls.begin(), ls.end(), greater<PII>());

  for(int i = 1; i < n; i++) {
    int x;
    cin >> x;
    children[x - 1].PB(i);
  }

  dfs(0, start, sz, children);

  BIT bit;
  bit.setter(n);
  VI ret(n);
  for(auto& x: ls) {
    int r = start[x.y] + sz[x.y] - 1;
    int l = start[x.y];
    ret[x.y] = bit.qry(r) - bit.qry(l);
    bit.inc(start[x.y]);
  }

  for(int i = 0; i < n; i++) {
    cout << ret[i] << endl;
  }

  return 0;
}
