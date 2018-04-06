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

bool arr[105][105];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  for( int tc = 1; ; ++tc ) {
    int m, n;
    cin >> m >> n;
    if( n * m == 0 )
      break;
    
    int k;
    cin >> k;
    
    for( int i = 0; i < m; ++i ) {
      for( int j = 0; j < n; ++j ) {
        arr[i][j] = false;
      }
    }
    
    for( int i = 0; i < k; ++i ) {
      int x, y;
      cin >> x >> y;
      arr[x][y] = true;
    }
    
    int g;
    cin >> g;
    
    for( int gen = 0; gen < g; ++gen ) {
      int newarr[105][105];
      for( int i = 0; i < m; ++i ) {
        for( int j = 0; j < n; ++j ) {
          int newj = (j + n/2) % n;
          int near = arr[i][(j+1) % n] + arr[i][(j-1+n) % n];
          if( i == 0 )
            near += arr[0][newj] + arr[0][(newj+1)%n] + arr[0][(newj-1+n)%n];
          else
            near += arr[i-1][j] + arr[i-1][(j+1)%n] + arr[i-1][(j-1+n)%n];
          if( i == m - 1 )
            near += arr[m-1][newj] + arr[m-1][(newj+1)%n] + arr[m-1][(newj-1+n)%n];
          else
            near += arr[i+1][j] + arr[i+1][(j+1)%n] + arr[i+1][(j-1+n)%n];
          if( near == 3 )
            newarr[i][j] = true;
          else if( near <= 1 || near >= 4 )
            newarr[i][j] = false;
          else
            newarr[i][j] = arr[i][j];
        }
      }
      
      for( int i = 0; i < m; ++i ) {
        for( int j = 0; j < n; ++j ) {
          arr[i][j] = newarr[i][j];
        }
      }
    }
    
    int cnt = 0;
    int first = -1;
    int last = -1;
    for( int i = 0; i < m; ++i ) {
      for( int j = 0; j < n; ++j ) {
        if( arr[i][j] ) {
          cnt++;
          if( first == -1 )
            first = i * n + j;
          last = i * n + j;
        }
      }
    }
    
    cout << "Case " << tc << ": ";
    if( cnt == 0 ) {
      cout << "0 -1 -1 -1 -1\n";
    } else {
      cout << cnt << " " << first / n << " " << first % n << " " << last / n << " " << last % n << "\n";
    }
  }
  
  return 0;
}
