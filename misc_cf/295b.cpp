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

#define MN 505

int adj[MN][MN];
int dist[MN][MN];
int dels[MN];
ll answers[MN];
bool added[MN];

int main()
{
  int n;
  cin >> n;
  for( int i = 0; i < n; ++i )
  {
    for( int j = 0; j < n; ++j )
    {
      cin >> adj[i][j];
      dist[i][j] = adj[i][j];
    }
  }
  for( int i = n - 1; i >= 0; --i )
  {
    cin >> dels[i];
    dels[i]--;
  }

  for( int i = 0; i < n; ++i )
  {
    int add = dels[i];
    for( int j = 0; j < n; ++j )
    {
      for( int k = 0; k < n; ++k )
      {
        if( dist[j][k] > dist[j][add] + dist[add][k] )
        {
          dist[j][k] = dist[j][add] + dist[add][k];
        }
      }
    }

    added[add] = true;

    ll ans = 0;
    for( int j = 0; j < n; ++j )
    {
      for( int k = 0; k < n; ++k )
      {
        if( added[j] && added[k] )
          ans += dist[j][k];
      }
    }
    answers[n - 1 - i] = ans;
  }

  for( int i = 0; i < n; ++i )
  {
    cout << answers[i] << " ";
  }

  return 0;
}
