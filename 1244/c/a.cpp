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

ll n, p, d, w;

bool ok(ll a) {
  ll win = a*w;
  ll copp = p;
  copp -= win;
  if(copp % d == 0) {
    if((a + copp/d) <= n) {
      return true;
    }
  }
  return false;
}

vector<ll> get(ll a) {
  vector<ll> ret(3);
  ret[0] = a;
  ret[1] = (p - a*w)/d;
  ret[2] = n - ret[0] - ret[1];
  return ret;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("c.in", "r", stdin);    
  freopen("c.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  cin >> n >> p >> w >> d;

  for(ll i = 0; i < w; i++) {
    if((p - i*d)%w == 0) {
      ll x, y, z;
      y = i;
      x = (p - i*d)/w;
      z = n - x - y;
      if(z < 0 or x < 0 or y < 0) {
        continue;
      }
      cout << x << " " << y << " " << z << endl;
      return 0;
    }
  }

  cout << -1 << endl;



  return 0;
}
