#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<string, string> mss;

#define rep(i, begin, end) for (__typeof(begin) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define trace(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod int(1e9+7)

#define MN 105

int dpnd[MN]; // no d
int dpd[MN]; // d

int main()
{
  int n, k, d;
  cin >> n >> k >> d;

  dpnd[0] = 1;
  rep(i, 1, n+1)
  {
    rep(j, 1, min(k, i) + 1)
    {
      if( j < d )
      {
        dpnd[i] += dpnd[i-j];
        dpnd[i] %= mod;
      }
    }
  }

  rep(i, 1, n+1)
  {
    rep(j, 1, min(k, i) + 1)
    {
      dpd[i] += dpd[i-j];
      dpd[i] %= mod;
      if( j >= d )
        dpd[i] += dpnd[i-j];
      dpd[i] %= mod;
    }
  }
  cout << dpd[n] << "\n";

  return 0;
}
