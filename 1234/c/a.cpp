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
    VVI vals(2, VI(n));
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < n; j++) {
        char c;
        cin >> c;
        if(c <= '2') vals[i][j] = 1;
        else vals[i][j] = 2;
      }
    }
    int i, j;
    i = 0;

    for(j = 0; j < n; j++) {
      if(vals[i][j] == 2) {
        if(vals[i^1][j] != 2) {
          break;
        }
        i ^= 1;
      }
    }

    if(j == n and i == 1) {
      cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    
  }

  return 0;
}
