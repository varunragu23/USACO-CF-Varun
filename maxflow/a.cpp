/*
ID: varunra2
LANG: C++
TASK: maxflow
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

VI par;
VI sz;

int find(int x) {
  while(x != par[x]) x = par[x];
  return par[x];
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if(sz[u] < sz[v]) swap(u, v);
  par[v] = u;
  sz[u] += sz[v];
}

// cp-algorithms tarjan's off-line lca algorithm
void dfs1(int v, VVI& adj, vector<VII>& qs, VI& ans, vector<bool>& vis, VI& anc) {
  vis[v] = true;
  anc[v] = v;
  for(int u: adj[v]) {
    if(!vis[u]) {
      dfs1(u, adj, qs, ans, vis, anc);
      merge(v, u);
      anc[find(v)] = v;
    }
  }
  for(PII oth: qs[v]) {
    if(vis[oth.x]) {
      ans[oth.y] = anc[find(oth.x)];
    }
  }
}

void dfspar(int cur, int from, VVI& adj, VI& parent) {
  parent[cur] = from;
  for(auto& x: adj[cur]) {
    if(x == from) continue;
    dfspar(x, cur, adj, parent);
  }
}

int dfspref(int cur, int from, VVI& adj, VI& pref) {
  for(auto& x: adj[cur]) {
    if(x == from) continue;
    pref[cur] += dfspref(x, cur, adj, pref);
  }
  return pref[cur];
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("maxflow.in", "r", stdin);    
  freopen("maxflow.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n, k;
  cin >> n >> k;

  VVI adj(n);

  vector<VII> qs(n);

  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].PB(b);
    adj[b].PB(a);
  }

  debug(adj);

  for(int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    qs[a].PB(MP(b, i));
    qs[b].PB(MP(a, i));
  }

  debug(qs);

  VI ans(k);

  vector<bool> vis(n, false);

  VI anc(n);

  par.resize(n);
  sz.resize(n);

  iota(par.begin(), par.end(), 0);

  for(int i = 0; i < n; i++) {
    sz[i] = 1;
  }

  dfs1(0, adj, qs, ans, vis, anc);

  VI parent(n);

  parent[0] = -1;

  dfspar(0, -1, adj, parent);

  VI pref(n, 0);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < qs[i].size(); j++) {
      if(i < qs[i][j].x) {
        pref[i]++;
        pref[qs[i][j].x]++;
      }
    }
  }
  debug(ans);
  debug(parent);
  for(int i = 0; i < ans.size(); i++) {
    pref[ans[i]]--;
    if(ans[i] != 0) {
      pref[parent[ans[i]]]--;
    }
  }
  debug(pref);
  dfspref(0, -1, adj, pref);

  cout << *max_element(pref.begin(), pref.end()) << endl;
  debug(pref);

  return 0;
}
