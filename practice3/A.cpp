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

map<ii, double> memo;
double ans(int n, int k)
{
  if( k == 0 ) {
    return n;
  }
  if( memo.count({n, k}) )
    return memo[{n, k}];
  return memo[{n, k}] = ans(abs(n-1), k-1)/2 + ans(n, k-1)/2;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  
  int n, k;
  cin >> n >> k;
  
  cout << n - ans(n, k) << endl;
  
  return 0;
}
