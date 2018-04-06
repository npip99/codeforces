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
  
  ll n, k;
  cin >> n >> k;
  
  ll cur = 1;
  for( int i = 0; i < n; ++i ) {
    ll val;
    cin >> val;
    cur = cur*val / __gcd(cur, val);
    cur = __gcd(cur, k);
  }
  
  cout << (cur % k == 0 ? "Yes\n" : "No\n");
  
  return 0;
}
