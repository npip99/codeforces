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

char grid[35][35];
ll dp[35][35];

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int m, n;
  cin >> m >> n;
  
  for( int i = 0; i < m; ++i ) {
    for( int j = 0; j < n; ++j ) {
      cin >> grid[i][j];
      if( grid[i][j] == 'B' ) {
        for( int i2 = 0; i2 <= i; ++i2 ) {
          for( int j2 = 0; j2 <= j; ++j2 ) {
            if( grid[i2][j2] == 'R' ) {
              cout << "0\n";
              return 0;
            }
            grid[i2][j2] = 'B';
          }
        }
      }
    }
  }
  
  for( int i = 0; i < m; ++i ) {
    for( int j = 0; j < n; ++j ) {
      if( grid[i][j] == 'R' ) {
        for( int i2 = i; i2 < m; ++i2 ) {
          for( int j2 = j; j2 < n; ++j2 ) {
            if( grid[i2][j2] == 'B' ) {
              cout << "0\n";
              return 0;
            }
            grid[i2][j2] = 'R';
          }
        }
      }
    }
  }
  
  for( int i = 0; i < m; ++i ) {
    for( int j = 0; j < n; ++j ) {
      if( (grid[i][j] == 'B' && (j == n-1 || grid[i][j+1] != 'B')) || grid[i][j] == '.' ) {
        if( i == 0 ) {
          dp[i][j] = 1;
        } else {
          for( int j2 = j; j2 < n; j2++ ) {
            dp[i][j] += dp[i-1][j2];
          }
        }
      }
    }
  }
  
  ll ans = 0;
  for( int i = 0; i < m; ++i ) {
    if( grid[i][0] != 'B' ) {
      if( i == 0 ) {
        ans = 1;
      } else {
        for( int j = 0; j < n; ++j ) {
          ans += dp[i-1][j];
        }
      }
    }
  }
  for( int j = 0; j < n; ++j ) {
    ans += dp[m-1][j];
  }
  
  cout << ans << "\n";
  
  return 0;
}