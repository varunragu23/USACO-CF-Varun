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
  freopen("d.in", "r", stdin);    
  freopen("d.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  VI vals(n);
  int fqs = 0;
  int sqs = 0;
  for(int i = 0; i <n ; i++) {
    char x;
    cin >> x;
    if(x == '?') {
      x = '0';
      if(i < n/2)
      fqs++;
      else 
      sqs++;
    }
    vals[i] = x - '0';

  }

  /*for(int i = 0; i < n; i++) {
    cout << vals[i] << " ";
  }

  cout << endl;
*/
  int first, second;
  first = 0;
  second = 0;
  for(int i = 0; i < n/2; i++) {
    first += vals[i];
    second += vals[i + n/2];
  }

  int m = min(fqs, sqs);

  fqs -= m;
  sqs -= m;
  // cout << first << endl;
  // cout << fqs << endl;
  // cout << second << endl;
  // cout << sqs << endl;
  if(first + (fqs/2)*9 != second + (sqs/2*9)) {
    cout << "Monocarp" << endl;
  }
  else cout << "Bicarp" << endl;
  
  return 0;
}
