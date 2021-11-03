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

int grid[1005];
int dp[1005][1005][2];
int best[1005][2];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < m; ++j ) {
      char c;
      cin >> c;
      if( c == '#' )
        grid[j]++;
    }
  }
  
  // dp[0][1][b] = !grid[0] 2
  // dp[0][1][w] = grid[0] 4
  
  // dp[1][1][b] = !grid[1] + dp[0][any][w] 1 + 4 = 5
  // dp[1][1][w] = grid[1] + dp[0][any][b] 5 + 2 = 7
  // dp[1][2][b] = !grid[1] + dp[0][1][b] 1 + 
  // dp[1][2][w] = grid[1] + dp[0][1][w]
  
  // dp[2][1][b] = !grid[1] + min(dp[1][any][w])
  // dp[2][1][w] = grid[1] + min(dp[1][any][b])
  // dp[2][2][b] = !grid[1] + dp[1][1][b]
  // dp[2][2][w] = grid[1] + dp[1][1][w]
  // dp[2][3][b] = !grid[1] + dp[1][2][b]
  // dp[2][3][w] = grid[1] + dp[1][2][w]
  
  for( int col = 0; col < m; ++col ) {
    dp[col][1][0] = n - grid[col];
    dp[col][1][1] = grid[col];
    if( col > 0 )
    {
      dp[col][1][0] += best[col-1][1];
      dp[col][1][1] += best[col-1][0];
    }
    for( int len = 2; len <= min(col + 1, y); ++len ) {
      dp[col][len][0] = n - grid[col] + dp[col-1][len-1][0];
      dp[col][len][1] = grid[col] + dp[col-1][len-1][1];
    }
    best[col][0] = best[col][1] = inf;
    for( int len = x; len <= min(col + 1, y); ++len ) {
      best[col][0] = min(best[col][0], dp[col][len][0]);
      best[col][1] = min(best[col][1], dp[col][len][1]);
    }
  }
  
  cout << min(best[m-1][0], best[m-1][1]) << endl;
  
  return 0;
}
