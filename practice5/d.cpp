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

mii adj[50005];
bool good[50005];

bool rainbow(int node, int par, int prev) {
  static int memo[50005]; // 1 = false, 2 = true
  
  if( memo[node] )
    return memo[node]-1;
  
  for( auto& edge : adj[node] ) {
    if( edge.first != par ) {
      if( edge.second == prev || !rainbow(edge.first, node, edge.second) ) {
        memo[node] = 1;
        return false;
      }
    }
  }
  memo[node] = 2;
  return true;
}

void dfs(int node, int par = -1, int prev = -1) {
  int nrain = 0;
  map<int, vi> edges;
  for( auto& edge : adj[node] ) {
    if( edge.first != par ) {
      if( !rainbow(edge.first, node, edge.second) ) {
        nrain++;
      }
      edges[edge.second].push_back(edge.first);
    }
  }
  if( nrain == 0 ) {
    good[node] = true;
  }
  if( nrain < 2 ) { // Don't iter if colored paths wipe each other out
    for( auto& kv : edges ) {
      if( kv.first != prev && kv.second.size() == 1 ) {
        if( nrain == 0 ) {
          dfs(kv.second[0], node, kv.first);
        } else if( !rainbow(kv.second[0], node, kv.first) ) { // If it's the only not rainbow
          dfs(kv.second[0], node, kv.first);
        }
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  for( int i = 0; i < n - 1; ++i ) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][b] = c;
    adj[b][a] = c;
  }
  
  dfs(1);
  
  int sz = 0;
  for( int i = 1; i <= n; ++i ) {
    sz += good[i];
  }
  cout << sz << "\n";
  for( int i = 1; i <= n; ++i ) {
    if( good[i] ) {
      cout << i << "\n";
    }
  }
  
  return 0;
}
