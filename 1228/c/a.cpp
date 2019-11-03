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

ll cnt(ll x, ll n) {
  ll ret = 0;
  while(n) {
    ret += (n/x);
    n /= x;
  }
  return ret;
}


ll binpow(ll base, ll pow) {
  ll ret = 1LL;
  while(pow) {
    if(pow%(2LL) == 1LL) {
      ret *= base;
      ret %= MOD;
    }
    pow /= 2;
    base = base*base;
    base %= MOD;
  }
  return ret;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("c.in", "r", stdin);    
  freopen("c.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  ll x;
  ll n;
  cin >> x >> n;

  vector<ll> primes;

  for(int i = 2; i*i <= x; i++) {
    if(x % i == 0) {
      primes.PB(i);
      while(x % i == 0) x/=i;
    }
  }

  if(x > 1) {
    primes.PB(x);
  }  

  ll ans = 1LL;

  for(auto& p: primes) {
    ans *= (binpow(p, cnt(p, n)) % MOD);
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
