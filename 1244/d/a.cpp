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
int n;

ll dfs(int cur, int from, VI& color, int ind, VVI& adj, VVI& cost) {
  ind %= 3;
  if(adj[cur].size() == 1 and from != -1) {
    return cost[cur][color[ind]];
  }
  int to;
  for(auto& x: adj[cur]) {
    if(x == from) continue;
    to = x;
  }
  return cost[cur][color[ind]] + dfs(to, cur, color, ind + 1, adj, cost);
}

void color(int cur, int from, VI& col, int ind, VI& get, VVI& adj) {
  ind %= 3;
  get[cur] = col[ind];
  for(auto& x: adj[cur]) {
    if(x == from) continue;
    color(x, cur, col, ind + 1, get, adj);
  }
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("d.in", "r", stdin);    
  freopen("d.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  
  cin >> n;

  VVI cost(n, VI(3));

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < n; j++) {
      cin >> cost[j][i];
    }
  }

  VVI adj(n);

  for(int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  //by pigeonhole principle

  for(int i = 0; i < n; i++) {
    if(adj[i].size() > 2) {
      cout << -1 << endl;
      return 0;
    }
  }

  // tree is now a line cuz two edges per node, just find root and six diff possibilities

  int root = -1;

  for(int i = 0; i < n; i++) {
    if(adj[i].size() == 1) {root = i; break;}
  }

  VVI types = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

  ll ret;
  VI get(n);
  vector<ll> wich(6);
  for(int i = 0; i < 6; i++) {
    wich[i] = dfs(root, -1, types[i], 0, adj, cost);
  }

  auto it = min_element(wich.begin(), wich.end());

  int ind = it - wich.begin();

  color(root, -1, types[ind], 0, get, adj);

  cout << *it << endl;

  for(int i = 0; i < n; i++) {
    cout << get[i] + 1 << " ";
  }
  cout << endl;

  return 0;
}
