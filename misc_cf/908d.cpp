#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

// dp[k][last] = sum over l from l=0 to last of dp[k-1][l]*(# of IS from l+1 ... last)
// 

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef set<int> si;
typedef unordered_map<int, int> mii;
typedef unordered_map<string, int> msi;
typedef unordered_map<string, string> mss;

#define err(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod ll(1e9+7)

ll dp[1000][1000]; // dp[a's][ab's]

ll modpow(ll b, ll e) {
  b %= mod;
  ll ret = 1;
  while( e > 0 ) {
    if( e & 1 )
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  ll k, pa, pb;
  cin >> k >> pa >> pb;
  
  ll dinv = modpow(pa+pb, mod-2);
  ll pbinv = modpow(pb, mod-2);
  for( int i = k-1; i > 0; --i ) {
    for( int j = k-1; j >= 0; --j ) {
      if( i + j >= k ) {
        // i a's, goal is k. we have j ab's. next b kills it.
        // sum of (u/(u+v))^n * (v/(u+v)) * (i+n) from n=0 to infinity = (u+iv) / v
        dp[i][j] = (j + (pa+i*pb) % mod * pbinv) % mod;
      } else {
        dp[i][j] = (dp[i+1][j] * pa + dp[i][j+i] * pb) % mod * dinv % mod;
      }
    }
  }
  
  cout << dp[1][0] << endl;
  
  return 0;
}
