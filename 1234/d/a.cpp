/*
ID: varunra2
LANG: C++
TASK: d
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
  freopen("d.in", "r", stdin);    
  freopen("d.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  string s;
  cin >> s;

  vector<SETI> locs(26);

  for(int i = 0; i < s.size(); i++) {
    locs[s[i] - 'a'].insert(i);
  }

  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if(type == 1) {

      int pos;
      char c;
      cin >> pos >> c;
      pos--;
      locs[s[pos] - 'a'].erase(pos);
      s[pos] = c;
      
      locs[c - 'a'].insert(pos);
    }
    else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      int ret = 0;
      for(int j = 0; j < 26; j++) {
        auto it = locs[j].lower_bound(l);
        ret += (it != locs[j].end() and *it <= r);
      }
	
      cout << ret << endl;
    }
  }

  return 0;
  
}
