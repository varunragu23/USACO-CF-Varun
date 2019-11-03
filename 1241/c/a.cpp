/*
ID: varunra2
LANG: C++
TASK: c
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

bool works(int x, vector<ll>& p, vector<ll> times, ll k) {
  sort(times.begin(), times.begin() + x + 1, greater<ll>());
  //debug(times);
  ll cur = 0;
  for(int i = 0; i <= x; i++) {
    cur += (p[i]*times[i]);
    //debug(cur);
  }
  return cur >= k;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("c.in", "r", stdin);    
  freopen("c.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while(q--) {
    int n;
    cin >> n;

    vector<ll> p(n);

    for(int i = 0; i < n; i++) {
      cin >> p[i];
      p[i] /= 100;
    }

    ll x, a, y, b;

    cin >> x >> a >> y >> b;
    ll k;
    cin >> k;
    vector<ll> times(n, 0);
    for(int i = a - 1; i < n; i += a) {
      times[i] += x;
    }
    for(int i = b - 1; i < n; i += b) {
      times[i] += y;
    }
    //debug(times);
    sort(p.begin(), p.end(), greater<ll>());
    //debug(p);
    if(!works(n - 1, p, times, k)) {
      cout << -1 << endl;
      continue;
    }
    // binary search
    int z = -1;
    for(int b = n; b >= 1; b /= 2) {
      while(!works(z + b, p, times, k)) z += b;
    }
    
    

    cout << z + 2 << endl;

  }
  return 0;
}
