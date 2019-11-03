/*
ID: varunra2
LANG: C++
TASK: b
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
  freopen("b.in", "r", stdin);    
  freopen("b.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int q;
  cin >> q;

  while(q--) {
    int n, r;
    cin >> n >> r;
    VI vals(n);
    for(int i = 0; i < n; i++) {
      cin >> vals[i];
    }
    sort(vals.begin(), vals.end(), greater<int>());
    auto last = unique(vals.begin(), vals.end());
    vals.erase(last, vals.end());
    int ret = 0;
    for(int i = 0; i < vals.size(); i++) {
      if(ret*r >= vals[i]) {
        break;
      }
      ret++;
    }
    cout << ret << endl;
  }

  return 0;
}
