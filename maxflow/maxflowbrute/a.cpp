/*
ID: varunra2
LANG: C++
TASK: haybales brute forced
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
  freopen("haybales.in", "r", stdin);    
  freopen("haybales.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n, q;
  cin >> n >> q;

  vector<ll> vals(n);

  for(int i = 0; i < n; i++) {
    cin >> vals[i];
  }

  for(int i = 0; i < q; i++) {
    char c;
    cin >> c;
    if(c == 'M') {
      ll mn = 1e18;
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      for(int j = a; j <= b; j++) {
        mn = min(mn, vals[j]);
      }
      cout << mn << endl;
    }
    if(c == 'S') {
      ll sm = 0;
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      for(int j = a; j <= b; j++) {
        sm += vals[j];
      }
      cout << sm << endl;
    }
    if(c == 'P') {
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      for(int j = a; j <= b; j++) {
        vals[j] += c;
      }
    }
  }

  return 0;
}
