/*
ID: varunra2
LANG: C++
TASK: fortmoo
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

int qry(VVI& x, int i, int j, int y, int z) {
  return x[y + 1][z + 1] - x[i][z + 1] - x[y + 1][j] + x[i][j];
} 

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("fortmoo.in", "r", stdin);    
  freopen("fortmoo.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;

  VVI vals(n + 1, VI(m + 1, 0));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c;
      cin >> c;
      vals[i + 1][j + 1] = vals[i + 1][j] + vals[i][j + 1] - vals[i][j];
      vals[i + 1][j + 1] += (c == 'X');
    }
  }

  int mx = 0;

  for(int i = 0; i < m; i++) {
    for(int j = i; j < m; j++) {
      int lr = -1;
      for(int k = 0; k < n; k++) {
        bool valid = (qry(vals, k, i, k, j) == 0);
        if(valid) {
          mx = max(mx, j - i + 1);
        }
        if(valid and lr >= 0) {
          mx = max(mx, (k - lr + 1)* (j - i + 1));
        }
        if(qry(vals, k, j, k, j) > 0 or qry(vals, k, i, k, i) > 0) {
          lr = -1;
        }
        if(valid and lr == -1) {
          lr = k;
        }
      }
    }
  }

  cout << mx << endl;

  return 0;
}
