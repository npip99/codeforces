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
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<string, string> mss;

#define trace(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod int(1e9+7)

int arr[200005]; // input numbers
bool shelf[200005]; // numbers that are on the shelf
int cnt[500005]; // number of multiples of i on the shelf

ll common(int n, bool add)
{
  int nf = 0; // number of factors
  int facts[10]; // factors
  
  // get factors
  for( int i = 2; i*i <= n && n > 1; i++ ) {
    if( n % i == 0 ) {
      facts[nf] = i;
      while( n % i == 0 ) {
        n /= i;
      }
      nf++;
    }
  }
  if( n > 1 ) {
    facts[nf] = n;
    nf++;
  }
  
  // P.I.E.
  ll pairs = 0;
  for( int i = 1; i < (1 << nf); ++i ) {
    int num = 1, sgn = -1;
    for( int j = 0; j < nf; ++j ) {
      if( (i >> j) & 1 ) {
        num *= facts[j];
        sgn *= -1;
      }
    }
    cnt[num] += add ? 1 : -1;
    pairs += sgn * cnt[num];
  }
  if( nf > 0 && add ) // if n != 1 && added n, (n, n) was counted
    pairs--; // don't count (n, n)
                   
  return pairs;
}

int main()
{
  int n, q;
  cin >> n >> q;
  
  for( int i = 0; i < n; ++i ) {
    cin >> arr[i];
  }
  
  ll ans = 0;
  int nshelf = 0;
  for( int i = 0; i < q; ++i ) {
    int x;
    cin >> x;
    x--;
    
    if( !shelf[x] )
    {
      shelf[x] = true;
      nshelf++;
      ans += nshelf - 1 - common(arr[x], true); // coprime pairs after addition = nshelf - 1 - common pairs
    } else {
      shelf[x] = false;
      nshelf--;
      ans -= nshelf - common(arr[x], false); // coprime pairs after removal = nshelf - common pairs
    }
    
    cout << ans << endl;
  }
  
  return 0;
}
