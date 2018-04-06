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

#define err(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod int(1e9+7)



int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int t;
  cin >> t;
  for( int tc = 1; tc <= t; tc++ )
  {
    ll n;
    cin >> n;
    if( n % 3 == 0 ) {
      cout << n/3 << " " << n/3 << " " << n/3 << "\n";
    } else if( n % 4 == 0 ) {
      cout << n/4 << " " << n/4 << " " << n/2 << "\n";
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
  
  return 0;
}
