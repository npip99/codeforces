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

int fib[300];
int ans[300];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int s, k;
  cin >> s >> k;
  
  int len = 0;
  ans[len++] = 0;
  fib[0] = 1;
  for( int i = 1; i < 300; i++ )
  {
    for( int j = max(i - k, 0); j < i; ++j ) {
      fib[i] += fib[j];
    }
    if( fib[i] > s ) {
      i--;
      while( s > 0 )
      {
        ans[len++] = fib[i];
        s -= fib[i];
        while( fib[i] > s )
          i--;
      }
      
      break;
    }
  }
  
  cout << len << "\n";
  for( int i = 0; i < len; ++i ) {
    cout << ans[i] << " ";
  }
  
  return 0;
}
