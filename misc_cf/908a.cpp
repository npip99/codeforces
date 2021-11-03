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
  
  string s;
  cin >> s;
  set<char> check{'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'};
  int ans = 0;
  for( char c : s ) {
    if( check.count(c) ) {
      ans++;
    }
  }
  cout << ans << endl;
  
  return 0;
}
