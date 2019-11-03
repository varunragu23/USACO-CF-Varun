/*
ID: varunra2
LANG: C++
TASK: castle
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

int n, m;

int conv(int x, int y) {
  return n*m + y;
}

void dfs(int x, VVI& adj, vector<bool>& vis, VI& cur) {
  if(vis[x]) return;
  cur.PB(x);
  vis[x] = true;
  for(auto& y: adj[x]) {
    dfs(y, adj, vis, cur);
  }
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("castle.in", "r", stdin);    
  freopen("castle.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    //VVI vals(n, VI(m));

    VVI adj(n*m);

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int x;
        cin >> x;
        if(x >= 8) {
          x -= 8;
        }
        else if(i < n - 1) adj[conv(i, j)].PB(conv(i + 1, j));

        if(x >= 4) {
          x -= 4;
        }
        else if(i < m - 1) adj[conv(i, j)].PB(conv(i, j + 1));
        
        if(x >= 2) {
          x -= 2;
        }
        else if(i > 0) adj[conv(i, j)].PB(conv(i - 1, j));

        if(x >= 1) {
          x -= 1;
        }
        else if(j > 0) adj[conv(i, j)].PB(conv(i, j - 1));
      }
    }

    VVI gps;

    vector<bool> vis(n*m, false);

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(vis[conv(i, j)]) continue;
        VI cur;
        dfs(conv(i, j), adj, vis, cur);
        gps.PB(cur);
      }
    }
    cout << gps.size() << endl;
    MPII comp;
    int mxsz = 0;

    for(int i = 0; i < gps.size(); i++) {
      mxsz = max(mxsz, (int) gps[i].size());
      for(int j = 0; j < gps[i].size(); j++) {
        comp[gps[i][j]] = i;
      }
    }
    cout << mxsz << endl;
    int maxcomb = 0;
    PII used;
    char dir;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int cur = conv(i, j);
        VI use;
        if(i > 0) {
          use.PB(conv(i - 1, j));
        }
        if(j > 0) {
          use.PB(conv(i, j - 1));
        }
        if(i < n - 1) {
          use.PB(conv(i + 1, j));
        }
        if(j < n - 1) {
          use.PB(conv(i, j + 1));
        }
        for(int k = 0; k < use.size(); k++) {
          if(comp[cur] != comp[use[k]]) {
            if(maxcomb < gps[comp[cur]].size() + gps[comp[use[k]]].size()) {
              maxcomb = gps[comp[cur]].size() + gps[comp[use[k]]].size();
              used.x = i + 1;
              used.y = j + 1;
              int t = use[k];
              if(conv(i - 1, j) == t) {
                dir = 'S';
              }
              else if(conv(i, j - 1) == t) {
                dir = 'W';
              }
              else if(conv(i, j + 1) == t) {
                dir = 'E';
              }
              else dir = 'N';
            }
          }
        }
      }
    }

    cout << maxcomb << endl;
    cout << used.x << " " << used.y << " " << dir << endl;



  return 0;
}
