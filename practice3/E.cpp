#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>

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

#define err(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod int(1e9+7)

int m[1000005];
int arr[1000005];
map<ii, set<pair<long, int>>> lines;

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int tx, ty, N;
  cin >> tx >> ty >> N;
  for( int i = 0; i < N; ++i ) {
    int x, y, h;
    cin >> x >> y >> h;
    x -= tx;
    y -= ty;
    int gcd = __gcd(abs(x), abs(y));
    x /= gcd;
    y /= gcd;
    lines[{x, y}].insert({x*long(x) + y*long(y), h});
  }
  
  int ans = 0;
  for( pair<ii,set<pair<long, int>>> line : lines ) {
    int n = 0;
    for( auto& it : line.second ) {
      arr[n++] = it.second;
    }
    int l = 0;
    for( int i = 0; i < n; ++i ) {
      int lo = 1;
      int hi = l;
      while( lo <= hi ) {
        int mid = (lo+hi+1)/2;
        if( arr[m[mid]] < arr[i] )
          lo = mid + 1;
        else
          hi = mid - 1;
      }
      
      m[lo] = i;
      if( lo > l ) {
        l = lo;
      }
    }
    ans += l;
  }
  
  cout << ans << endl;
  
  return 0;
}
