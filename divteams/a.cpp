/*
ID: varunra2
LANG: C++
TASK: divteams
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
  freopen("divteams.in", "r", stdin);    
  freopen("divteams.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  VII vals(n);

  for(int i = 0; i < n; i++) {
    cin >> vals[i].x;
    vals[i].y = i;
  }
  sort(vals.begin(), vals.end());
  VI p, q;

  for(int i = 0; i < n; i++) {
    if(i%2) {
      q.PB(vals[i].y + 1);
    }
    else {
      p.PB(vals[i].y + 1);
    }
  }

  cout << p.size() << endl;
  for(int i = 0; i < p.size(); i++) {
    cout << p[i] << " ";
  }
  cout << endl;
  cout << q.size() << endl;

  for(int i = 0; i < q.size(); i++) {
    cout << q[i] << " ";
  }
  cout << endl;

  

  return 0;
}
