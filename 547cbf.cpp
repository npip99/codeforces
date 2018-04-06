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

#define MN 200005

int arr[MN];

int main()
{
  int n, q;
  cin >> n >> q;
  for( int i = 0; i < n; ++i ) {
    cin >> arr[i];
  }
  
  set<int> shelf;
  ll ans = 0;
  for( int i = 0; i < q; ++i ) {
    int x;
    cin >> x;
    x--;
    
    if( shelf.count(x) ) {
      shelf.erase(x);
      for( int k : shelf ) {
        if( __gcd(arr[k], arr[x]) == 1 ) {
          ans--;
        }
      }
    } else {
      for( int k : shelf ) {
        if( __gcd(arr[k], arr[x]) == 1 ) {
          ans++;
        }
      }
      shelf.insert(x);
    }
    cout << ans << endl;
  }
  
  return 0;
}
