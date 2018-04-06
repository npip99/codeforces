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

#define MN 1005

int mat[MN][MN];
int se[MN][MN];
int sw[MN][MN];
int ne[MN][MN];
int nw[MN][MN];

int main()
{
  int n, m;
  cin >> n >> m;

  for( int i = 1; i <= n; ++i ) {
    for( int j = 1; j <= m; ++j ) {
      cin >> mat[i][j];
    }
  }

  for( int i = 1; i <= n; ++i ) {
    for( int j = 1; j <= m; ++j ) {
      se[i][j] = max(se[i-1][j], se[i][j-1]) + mat[i][j];
    }
  }
  for( int i = 1; i <= n; ++i ) {
    for( int j = m; j >= 1; --j ) {
      sw[i][j] = max(sw[i-1][j], sw[i][j+1]) + mat[i][j];
    }
  }
  for( int i = n; i >= 1; --i ) {
    for( int j = 1; j <= m; ++j ) {
      ne[i][j] = max(ne[i+1][j], ne[i][j-1]) + mat[i][j];
    }
  }
  for( int i = n; i >= 1; --i ) {
    for( int j = m; j >= 1; --j ) {
      nw[i][j] = max(nw[i+1][j], nw[i][j+1]) + mat[i][j];
    }
  }

  int ans = 0;
  for( int i = 2; i < n; ++i ) {
    for( int j = 2; j < m; ++j ) {
      ans = max(ans, se[i][j-1] + nw[i][j+1] + sw[i-1][j] + ne[i+1][j]);
      ans = max(ans, se[i-1][j] + nw[i+1][j] + sw[i][j+1] + ne[i][j-1]);
    }
  }

  cout << ans << endl;

  return 0;
}
