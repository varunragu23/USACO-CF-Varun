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

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    VI plz(3);
    cin >> plz[0] >> plz[1] >> plz[2];
    string s;
    cin >> s;
    VI ret(n, -1);
    int wn = 0;
    for(int i = 0; i < n; i++) {
      int type;
      if(s[i] == 'R') type = 1;
      if(s[i] == 'P') type = 2;
      if(s[i] == 'S') type = 0;
      if(plz[type] > 0) {
        ret[i] = type;
        plz[type]--;
        wn++;
      }
    }
    if(2*wn >= n) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
      continue;
    }
    for(int i = 0; i < n; i++) {
      if(ret[i] == -1) {
        for(int j = 0; j < 3; j++) {
          if(plz[j] > 0) {ret[i] = j; plz[j]--; break;}
        }
      }
    }
    for(int i = 0; i < n; i++) {
      if(ret[i] == 0) {
        cout << "R"; 
      }
      else if(ret[i] == 1) {
        cout << "P";
      }
      else {
        cout << "S";
      }
    }
    cout << endl; 
  }

  return 0;
}
