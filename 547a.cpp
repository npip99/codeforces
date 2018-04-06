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

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define trace(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod int(1e9+7)

int main()
{
  ll m, h1, a1, x1, y1, h2, a2, x2, y2;
  cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
  
  ll start1 = -1;
  for( int i = 0; i < m + 5; i++ ) {
    if( h1 == a1 ) {
      start1 = i;
      break;
    }
    h1 = (h1 * x1 + y1) % m;
  }
  
  ll cycle1 = -1;
  for( int i = 0; i < m + 5; i++ ) {
    if( i != 0 && h1 == a1 ) {
      cycle1 = i;
      break;
    }
    h1 = (h1 * x1 + y1) % m;
  }
  
  ll start2 = -1;
  for( int i = 0; i < m + 5; i++ ) {
    if( h2 == a2 ) {
      start2 = i;
      break;
    }
    h2 = (h2 * x2 + y2) % m;
  }
  
  ll cycle2 = -1;
  for( int i = 0; i < m + 5; i++ ) {
    if( i != 0 && h2 == a2 ) {
      cycle2 = i;
      break;
    }
    h2 = (h2 * x2 + y2) % m;
  }
  
  if( start1 == -1 || start2 == -1 ) {
    cout << -1 << endl;
    return 0;
  }
  
  if( cycle1 == -1 || cycle2 == -1 ) {
    if( start1 == start2 )
      cout << start1 << endl;
    else if( cycle1 == -1 && cycle2 != -1 && start1 - start2 > 0 && (start1 - start2) % cycle2 == 0 )
      cout << start1 << endl;
    else if( cycle2 == -1 && cycle1 != -1 && start2 - start1 > 0 && (start2 - start1) % cycle1 == 0 )
      cout << start2 << endl;
    else
      cout << -1 << endl;
    return 0;
  }
  
  ll target = start2 - start1;
  ll t = -1;
  for( int y = 0; y < m + 5; y++ ) {
    if( ( target + cycle2 * y ) % cycle1 == 0 ) {
      t = cycle2 * y + start2;
      break;
    }
  }
  
  cout << t << endl;
  
  return 0;
}
