#include <iostream>
#include <algorithm>
#include <numeric>
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
  cin.tie(0);
  
  ll l, r, w;
  
  cin >> l >> r >> w;
  
  ll gcd = __gcd(r, w);
  
  if( r > w )
    swap(r, w);
  
  ll res = (r - 1) / gcd * gcd;
  
  if( l - res < w )
    cout << "DEADLOCK\n";
  else
    cout << "OK\n";
  
  return 0;
}
