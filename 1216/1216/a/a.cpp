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

  int n;
  cin >> n;

  string s;
  cin >> s;

  int ret = 0;

  for(int i = 0; i < n; i += 2) {
    if(s[i] == s[i + 1]) {
      ret++;
      if(s[i] == 'a') s[i + 1] = 'b';
      else s[i + 1] = 'a';
    }
  }

  cout << ret << endl;
  cout << s << endl;

  return 0;
}
