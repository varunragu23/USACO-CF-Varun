/*
ID: varunra2
LANG: C++
TASK: haybales
*/
//LAZY PROPOGATION ON RANGE TREE
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

class rgtree {

  vector<ll> mn;
  vector<ll> sum;
  vector<ll> lazy;
  int sz;


  private:
  //good
  ll evals(int ind, int l, int r) {
    return sum[ind] + (r - l + 1)*lazy[ind];
  }
  //good
  ll evalm(int ind, int l, int r) {
    return mn[ind] + lazy[ind];
  }
  //good
  void pD(int ind, int l, int r) {
    mn[ind] += lazy[ind];
    sum[ind] += (lazy[ind]*(r - l + 1));
    if(l != r) {
      lazy[2*ind] += lazy[ind];
      lazy[2*ind + 1] += lazy[ind];
    }
    lazy[ind] = 0;
  }
  //good
  void pU(int ind, int l, int r) {
    int m = (l + r)/2;
    mn[ind] = min(evalm(2*ind, l, m), evalm(2*ind + 1, m + 1, r));
    sum[ind] = evals(2*ind, l, m) + evals(2*ind + 1, m + 1, r);
  }
  //good
  void upd(int ind, int l, int r, int le, int ri,int inc) {
    if(r < le or l > ri) {
      return;
    }
    if(l >= le and r <= ri) {
      lazy[ind] += inc;
      return;
    }
    pD(ind, l, r);
    int m = (l + r)/2;
    upd(2*ind, l, m, le, ri, inc);
    upd(2*ind + 1, m + 1, r, le, ri, inc);
    pU(ind, l, r);
  }
  //good
  ll minQu(int ind, int l, int r, int le, int ri) {
    if(r < le or l > ri) {
      return LONG_MAX;
    }
    if(l >= le and r <= ri) {
      return evalm(ind, l, r);
    }
    pD(ind, l, r);
    int m = (l + r)/2;
    ll ret = LONG_MAX;
    ret = min(ret, minQu(2*ind, l, m, le, ri));
    ret = min(ret, minQu(2*ind + 1, m + 1, r, le, ri));
    pU(ind, l, r);
    return ret;
  }
  //good
  ll sumQu(int ind, int l, int r, int le, int ri) {
    if(r < le or l > ri) {
      return 0;
    }
    if(l >= le and r <= ri) {
      return evals(ind, l, r);
    }
    pD(ind, l, r);
    ll ret = 0;
    int m = (l + r)/2;
    ret += sumQu(2*ind, l, m, le, ri);
    ret += sumQu(2*ind + 1, m + 1, r, le, ri);
    pU(ind, l, r);
    return ret;
  }
  //good
  public:
  void pr() {
    debug(lazy);
    debug(mn);
    debug(sum);
  }
  //good
  void setter(int size) {
    sz = size;
    mn.resize(4*size);
    lazy.resize(4*size);
    sum.resize(4*size);
  }
  //good
  void update(int l, int r, int inc) {
    upd(1, 0, sz - 1, l, r, inc);
  }
  //good
  ll minQuery(int l, int r) {
    return minQu(1, 0, sz - 1, l, r);
  }
  //good
  ll sumQuery(int l, int r) {
    return sumQu(1, 0, sz - 1, l, r);
  }
};

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("haybales.in", "r", stdin);    
  freopen("haybales.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n, q;
  cin >> n >> q;

  rgtree r;
  r.setter(n);

  r.pr();
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    r.update(i, i, x);
  }
  r.pr();
  for(int i = 0; i < q; i++) {
    char c;
    cin >> c;
    int a, b;
    cin >> a >> b;
    //debug(c);
    // cerr << c << endl;
    // debug(a);
    // debug(b);
    a--;
    b--;
    int z = -1;
    if(c == 'P') {
      cin >> z;
      //debug(z);
    }
    if(c == 'M') {
      cout << r.minQuery(a, b) << endl;
    }
    else if(c == 'P') {
        r.update(a, b, z);
    }
    else {
      cout << r.sumQuery(a, b) << endl;
    }
  }
  r.pr();
  return 0;
}
