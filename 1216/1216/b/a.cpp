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
  freopen("b.in", "r", stdin);    
  freopen("b.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  ll n;
  cin >> n;

  vector<pair<ll, int>> vals(n);

  for(int i = 0; i < n; i++) {
    cin >> vals[i].first;
    vals[i].second = i;
  }

  ll ret = 0;

  sort(vals.begin(), vals.end(), greater<pair<ll, int>>());

  for(int i = 0; i < n; i++) {
    ret += (i * vals[i].first + 1);
  }

  cout << ret << endl;
  for(int i = 0; i < n; i++) {
    cout << vals[i].second + 1 << " ";
  }
  cout << endl;

  return 0;
}
