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

#define MN 100005

int val[26];
ll pre[MN];
map<ll, int[26]> sums;
int ch;

int main()
{
  for( int i = 0; i < 26; ++i ) {
    cin >> val[i];
  }
  
  string str;
  cin >> str;
  
  ll ans = 0;
  for( int i = 1; i <= str.length(); ++i ) {
    ch = str[i-1] - 'a';
    pre[i] = pre[i-1] + val[ch];
    ans += sums[pre[i-1]][ch];
    sums[pre[i]][ch]++;
  }
  
  cout << ans << endl;
  
  return 0;
}
