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

#define MN 100005;

mii diffs;

int main()
{
  int n;
  cin >> n;

  int ones = 0;
  int zeroes = 0;
  int ans = 0;
  
  diffs[0] = -1;
  for( int i = 0; i < n; ++i )
  {
    char ch;
    cin >> ch;
    ch == '1' ? ones++ : zeroes++;
    if( diffs.count(ones - zeroes) )
      ans = max(ans, i - diffs[ones - zeroes]);
    else
      diffs[ones - zeroes] = i;
  }

  cout << ans << "\n";

  return 0;
}
