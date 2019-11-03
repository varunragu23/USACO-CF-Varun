/*
ID: varunra2
LANG: C++
TASK: a
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
  freopen("a.in", "r", stdin);    
  freopen("a.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int a1, a2, k1, k2;
  cin >> a1 >> a2 >> k1 >> k2;
  int n;
  cin >> n;
  int mini;
  int maxi = 0;

  if(k1 > k2) {
    swap(k1, k2);
    swap(a1, a2);
  }

  int tk = a1*(k1 -1);
  tk += a2*(k2 - 1);

  mini = max(n - tk, 0);

  tk = min(n/k1, a1);

  n -= tk*k1;

  maxi += tk;

  tk = min(n/k2, a2);

  maxi += tk;

  cout << mini << " " << maxi << endl;

  return 0;
}
