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

int benefit[105][105];
int memo[105][105];
int ans[105];

int m, n;

int calc( int pre, int money, bool mem ) {
  if( pre == n )
    return 0;
  if( memo[pre][money] != -1 && mem ) {
    return memo[pre][money];
  }
  int bestv = benefit[pre][0] + calc(pre + 1, money, true);
  int bestm = 0;
  for( int m = 1; m <= money; ++m ) {
    int val = benefit[pre][m] + calc(pre + 1, money - m, true);
    if( val >= bestv ) {
      bestv = val;
      bestm = m;
    }
  }
  calc(pre + 1, money - bestm, false);
  ans[pre] = bestm;
  memo[pre][money] = bestv;
  return bestv;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  for( int tc = 1; ; ++tc ) {
    cin >> m >> n;
    if( m == 0 && n == 0 )
      break;
    for( int i = 0; i < n; ++i ) {
      double N, I, D;
      cin >> N >> I >> D;
      for( int j = 0; j <= m; ++j ) {
        benefit[i][j] = int(N * ((I + (j / (10.1 + j)) * D) / 100.0) + 0.5);
        memo[i][j] = -1;
      }
    }
    
    cout << "Case " << tc << ": " << calc( 0, m, true ) << "\n";
    for( int i = 0; i < n; ++i ) {
      cout << i << ":" << ans[i] << (i == n-1 ? "\n" : " ");
    }
  }
  
  return 0;
}
