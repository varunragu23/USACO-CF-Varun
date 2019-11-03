/*
ID: varunra2
LANG: C++
TASK: fencedin
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

int n, m;



int conv(int i, int j) {
  return (m)*i + j;
}

int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
  /*
  while(par[x] != x) x = par[x];
  return x;
  */
}

bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return false;
  par[y] = x;
  
  return true;
}

 static bool compbyw(const VI& a, const VI& b) {
   return a[2] < b[2];
 }

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("fencedin.in", "r", stdin);    
  freopen("fencedin.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int a, b;
  cin >> a >> b >> n >> m;

  VI vert(n + 1);
  VI hor(m + 1);

  for(int i = 0; i < n; i++) {
    cin >> vert[i];
  }

  for(int i = 0; i < m; i++) {
    cin >> hor[i];
  }

  sort(hor.begin(), hor.end());
  sort(vert.begin(), vert.end());
  
  for(int i = 0; i < n; i++) {
    vert[i] = vert[i + 1] - vert[i];
  }

  for(int i = 0; i < m; i++) {
    hor[i] = hor[i + 1] - hor[i];
  }

  vert[n] = b - vert[n];
  hor[m] = a - hor[m];

  sort(vert.begin(), vert.end());
  sort(hor.begin(), hor.end());



  // vert[n] = 0;
  // hor[m] = 0;

  // vert[n + 1] = b;
  // hor[m + 1] = a;

  

  
  // for(int i = 0; i <= m; i++) {
  //   for(int j = 0; j <= n; j++) {
  //     int u = conv(i, j);
  //     int v1, v2;
  //     int w1, w2;
  //     if(i > 0) {
  //       v1 = conv(i - 1, j);
  //       w1 = vert[j + 1] - vert[j];
  //       edg.push_back({w1, {u, v1}});
        
  //     }
  //     if(j > 0) {
  //       v2 = conv(i, j - 1);
  //       w2 = hor[i + 1] - hor[i];
  //       edg.push_back({w2, {u, v2}});
        
  //     }
  //   }
  // }
  n++;
  m++;


  ll ret = 1ll * vert[0] * (m - 1) + 1ll * hor[0] * (n - 1);

  for(int vi = 1, hi= 1; vi < n and hi < m;) {
    if(vert[vi] < hor[hi]) {
      ret += vert[vi++] * (m - hi);
    }
    else {
      ret += hor[hi++] * (n - vi);
    }
  }

  cout << ret << endl;

  

  return 0;
}
