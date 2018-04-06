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

int size[20][20];
int arr[20][20][400];
int r, c, w, h;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  for( int tc = 1; ; tc++ )
  {
    cin >> h >> w;
    r = 0;
    c = 0;
    
    if( h == 0 && w == 0 )
      break;
    
    for( int i = 0; i < h; ++i ) {
      for( int j = 0; j < w; ++j ) {
        cin >> arr[i][j][0];
        size[i][j] = 1;
      }
    }
    
    int m = w + h - 2;
    for( int chr = 0; chr < m; ++chr ) {
      char ch;
      cin >> ch;
      switch( ch ) {
      case 'L':
        for( int i = r; i < r+h; ++i ) {
          while( size[i][c] ) {
            arr[i][c+1][size[i][c+1]++] = -arr[i][c][--size[i][c]];
          }
        }
        c++;
        w--;
        break;
      case 'R':
        for( int i = r; i < r+h; ++i ) {
          while( size[i][c+w-1] ) {
            arr[i][c+w-2][size[i][c+w-2]++] = -arr[i][c+w-1][--size[i][c+w-1]];
          }
        }
        w--;
        break;
      case 'T':
        for( int i = c; i < c+w; ++i ) {
          while( size[r][i] ) {
            arr[r+1][i][size[r+1][i]++] = -arr[r][i][--size[r][i]];
          }
        }
        r++;
        h--;
        break;
      case 'B':
        for( int i = c; i < c+w; ++i ) {
          while( size[r+h-1][i] ) {
            arr[r+h-2][i][size[r+h-2][i]++] = -arr[r+h-1][i][--size[r+h-1][i]];
          }
        }
        h--;
        break;
      }
    }
    
    cout << "Case " << tc << ":";
    for( int i = 0; i < size[r][c]; ++i ) {
      if(arr[r][c][i] > 0)
        cout << " " << arr[r][c][i];
    }
    cout << "\n";
  }
  
  return 0;
}
