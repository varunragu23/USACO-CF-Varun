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

#define deb(x) cerr << #x << " = " << x << endl;

// util functions

#pragma endregion


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("c.in", "r", stdin);    
  freopen("c.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    VI a, b;

    for(int i = 0; i < n; i++) {
      if(s[i] == 'a' and t[i] == 'b') a.PB(i);
      else if(s[i] == 'b' and t[i] == 'a') b.PB(i);
    }

    if(a.size()%2 != b.size()%2) {
      cout << -1 << endl;
      return 0;
    }

    VII ops;

    for(int i = 0; i + 1 < a.size(); i+= 2) {
      ops.PB(MP(a[i], a[i + 1]));
    }

    for(int i = 0; i + 1 < b.size(); i += 2) {
      ops.PB(MP(b[i], b[i + 1]));
    }
    
    if(a.size()%2) {
      int as = a[a.size() - 1];
      int bs = b[b.size() - 1];
      ops.PB(MP(as, as));
      ops.PB(MP(as, bs));
    }
    if(ops.empty()) n = 0;
    else n = ops.size();
    cout << n << endl;

    for(int i = 0; i < ops.size(); i++) {
      cout << ops[i].x + 1 << " " << ops[i].y + 1 << endl;
    }

  return 0;
}
