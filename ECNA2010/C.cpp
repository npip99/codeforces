#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef tuple<string,int,int,int> siii;
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

int x[35][35];
int y[35][35];
int z[35][35];
string best[35][35][35];
bool vis[35][35][35];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  vector<siii> dirs;
  dirs.push_back(siii("0", 1, 0, 0));
  dirs.push_back(siii("1", -1, 0, 0));
  dirs.push_back(siii("2", 0, -1, 0));
  dirs.push_back(siii("3", 0, 1, 0));
  dirs.push_back(siii("4", 0, 0, -1));
  dirs.push_back(siii("5", 0, 0, 1));
  map<char, char> conv = {{'0','F'},{'1','B'},{'2','L'},{'3','R'},{'4','U'},{'5','D'}};
  
  for( int tc = 1; ; ++tc ) {
    int n;
    cin >> n;
    string k;
    getline(cin, k);
    
    
    if( n == 0 )
      break;
    
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < n; ++j ) {
        x[i][j] = y[i][j] = z[i][j] = false;
        for( int k = 0; k < n; ++k ) {
          best[i][j][k] = "";
          vis[i][j][k] = false;
        }
      }
    }
    
    for( int i = 0; i < n; ++i ) {
      getline(cin, k);
      for( int j = 0; j < n; ++j ) {
        if( k[j] == ' ')
          x[i][j] = true;
      }
    }
    for( int i = 0; i < n; ++i ) {
      getline(cin, k);
      for( int j = 0; j < n; ++j ) {
        if( k[j] == ' ')
          y[i][n-1-j] = true;
      }
    }
    for( int i = 0; i < n; ++i ) {
      getline(cin, k);
      for( int j = 0; j < n; ++j ) {
        if( k[j] == 'X')
          x[i][n-1-j] &= false;
      }
    }
    for( int i = 0; i < n; ++i ) {
      getline(cin, k);
      for( int j = 0; j < n; ++j ) {
        if( k[j] == 'X')
          y[i][j] &= false;
      }
    }
    for( int i = 0; i < n; ++i ) {
      getline(cin, k);
      for( int j = 0; j < n; ++j ) {
        if( k[j] == ' ')
          z[i][j] = true;
      }
    }
    for( int i = 0; i < n; ++i ) {
      getline(cin, k);
      for( int j = 0; j < n; ++j ) {
        if( k[j] == 'X')
          z[n-1-i][j] &= false;
      }
    }
    
    /*
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < n; ++j ) {
        cout << x[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < n; ++j ) {
        cout << y[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < n; ++j ) {
        cout << z[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    */
    
    vector<siii> q;
    q.push_back(siii("", n-2, n-2, n-2));
    vector<string> answers;
    while( q.size() > 0 ) {
      vector<siii> newq;
      bool flag = false;
      for( siii& elem : q ) {
        int X = get<1>(elem);
        int Y = get<2>(elem);
        int Z = get<3>(elem);
        if( vis[X][Y][Z] )
          continue;
        vis[X][Y][Z] = true;
        if( X == 1 && Y == 1 && Z == 1 ) {
          answers.push_back(best[X][Y][Z]);
          flag = true;
        }
        for( auto& dir : dirs ) {
          int newX = X + get<1>(dir);
          int newY = Y + get<2>(dir);
          int newZ = Z + get<3>(dir);
          //cout << newX << " " << newY << " " << newZ << endl;
          //cout << x[newX][newY] << " " << y[newY][newZ] << " " << z[newZ][newX] << endl;
          if( x[newZ][newY] && y[newZ][newX] && z[newX][newY] ) {
            string path = best[X][Y][Z] + get<0>(dir);
            if( best[newX][newY][newZ].length() == 0 || path < best[newX][newY][newZ] ) {
              best[newX][newY][newZ] = path;
              newq.push_back(siii(path + get<0>(dir), newX, newY, newZ));
            }
            //cout << newX << " " << newY << " " << newZ << " " << get<0>(dir);
          }
        }
      }
      if( flag )
        break;
      q = newq;
    }
    sort(answers.begin(), answers.end());
    if( answers.size() ) {
      for( char c : answers[0] ) {
        cout << conv[c];
      }
      cout << endl;
    }
  }
  
  return 0;
}
