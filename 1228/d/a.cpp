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

void logger() {
  cout << "check" << endl;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("d.in", "r", stdin);    
  freopen("d.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;

  VI ret(n, 0);

  vector<MPII> adj;
  logger();
  
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }
  
  logger();

  for(int i = 1; i <= 3; i++) {
    int j;
    for(j = 0; ret[j] and j < n; j++) {
    }
    if(j == n) break;
    ret[j] = i;
      for(int k = j + 1; k < n; k++) {
        if(ret[k]) continue;
        if(adj[j][k]) continue;
        ret[k] = i;
      }
    
  }

  logger();

  VVI a(n);

  for(int i = 0; i < n; i++) {
    for(auto& x: adj[i]) {
      if(x.second) a[i].PB(x.first);
    }
  }

  logger();

  for(int i = 0; i < n; i++) {
    if(ret[i] == 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  VI sz(3, 0);
  
  logger();

  for(int i = 0; i < n; i++) {
    sz[ret[i] - 1]++;
  }

  if(!(sz[0] and sz[1] and sz[2])) {
    cout << -1 << endl;
    return 0;
  }

  logger();

  for(int i = 0; i < n; i++) {
    if(a[i].size() != n - sz[ret[i] - 1]) {
      cout << -1 << endl;
      return 0;
    }
    for(auto& x: a[i]) {
      if(ret[x] == ret[i]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  logger();

  for(int i = 0; i < n; i++) {
    cout << ret[i] << " ";
  }

  cout << endl;



  return 0;
}
