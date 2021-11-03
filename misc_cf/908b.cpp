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

char grid[50][50];

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  
  ii start;
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < m; ++j ) {
      cin >> grid[i][j];
      if( grid[i][j] == 'S' ) {
        start = {i, j};
      }
    }
  }
  
  string dirs;
  cin >> dirs;
  
  int ans = 0;
  for( int up = 0; up < 4; ++up ) {
    for( int left = 0; left < 4; ++left ) {
      for( int right = 0; right < 4; ++right ) {
        for( int down = 0; down < 4; ++down ) {
          set<int> nums{up, left, right, down};
          if( nums.size() != 4 )
            continue;
          
          ii loc = start;
          for( char dir : dirs ) {
            dir -= '0';
            
            if( dir == up ) {
              loc.first--;
            } else if( dir == down ) {
              loc.first++;
            } else if( dir == left ) {
              loc.second--;
            } else if( dir == right ){
              loc.second++;
            }
            
            if( loc.first < 0 || loc.first >= n || loc.second < 0 || loc.second >= m ) {
              break;
            }
            if( grid[loc.first][loc.second] == '#' ) {
              break;
            }
            
            if( grid[loc.first][loc.second] == 'E' ) {
              ans++;
              break;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}
