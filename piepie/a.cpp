/*
ID: varunra2
LANG: C++
TASK: piepie
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

int n;
int d;
VI a;
VI b;
VI dist;
struct fs{
bool operator() (const int& x, const int& y) {
  return a[x] < a[y];
}
};

struct ss{

bool operator() (const int& x, const int& y) {
  return b[x] < b[y];
}

};


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("piepie.in", "r", stdin);    
  freopen("piepie.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  cin >> n >> d;

  a.resize(2*n);
  b.resize(2*n);
  dist.resize(2*n);

  for(int i = 0; i < 2*n; i++) {
    cin >> a[i] >> b[i];
    a[i]*= (-1);
    b[i] *= (-1);
    dist[i]  = -1;
  }

  multiset<int, fs> sa;
  multiset<int, ss> sb;

  VI que(2*n);

  int c = 0;
  int l = 0;
  // gettin' endposs's
  for(int i = 0; i < n; i++) {
    if(b[i] == 0) {
      que[l] = i;
      l++;

      dist[i] = 1;
    }
    else sb.insert(i);
    if(a[n + i] == 0) {
      que[l]  = n + i;
      l++;

      dist[n + i] = 1;
    }
    else sa.insert(n + i);
  }

  while(c < l) {
    int i = que[c];
    if(i < n) {
      while(true) {
        auto ita = sa.lower_bound(i);
        if(ita == sa.end() or a[*ita] > a[i] + d) {
          break;
        }
        dist[*ita] = dist[i] + 1;
        que[l] = *ita;
        l++;
        sa.erase(ita);
      }
    }
    else {
      while(true) {
        auto itb = sb.lower_bound(i);
        if(itb == sb.end() or b[*itb] > b[i] + d) {
          break;
        }
        dist[*itb] = dist[i] + 1;
        que[l] = *itb;
        l++;
        sb.erase(itb); 
      }
    }
    c++;
  }

  for(int i = 0; i < n; i++) {
    cout << dist[i] << endl;
  }


  return 0;
}
