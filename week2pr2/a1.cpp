#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

#define EPS 1e-9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()

typedef pair<int, int> PII;
typedef vector<int> VI;

const double pi = acos(-1.0);
typedef long int int32;
typedef long long int int64;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define watch(x) cerr << (#x) << " is " << (x) << endl
#define printvii(v)                                    \
  cerr << (#v) << "=";                                 \
  for_each(v.begin(), v.end(), [](PII i) -> void {     \
    cerr << "(" << i.first << "," << i.second << "),"; \
  });                                                  \
  cerr << endl;
#define printvi(v)                                                       \
  cerr << (#v) << "=";                                                   \
  for_each(v.begin(), v.end(), [](int i) -> void { cerr << i << ","; }); \
  cerr << endl;

int main(int argc, char const *argv[]) {
  freopen("week2pr2.in", "r", stdin);    
  freopen("week2pr2.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  /*int N, M;

  cin >> N >> M;

  cout << N << " " << M << endl;
  return 0;
  */

  int n;

  cin >> n;
 
  list<int> elim;

  for (int i = 1; i <= n; i++) {
    elim.push_back(i);
  }

/*  for (auto x: elim) {
    cout << x << " ";
  }
*/
  int fs = 0;
  while (elim.size() > 1) {
    /*auto it = elim.begin();
    auto back = elim.begin();*/
    elim.
    int count = 0;
    fs++;
    fs = fs % 2;
    if (fs == 1) {
    for (auto it = elim.begin(); it != elim.end(); it++) {
      if (!(count%2)) {
      elim.erase(it);
      }
      count++;
      //it++;


    }
    }
    else {
      auto it = elim.begin();
      elim.
      while(it != elim.end()) {
        if (!(count))
      }
    }
    /*
    for (auto x: elim) {
      cout << x << " ";
    }
    cout << endl; */
    for (auto x: elim) {
      cout << x << " ";
    }
    cout << endl;

  }

  cout << *elim.begin();

}
