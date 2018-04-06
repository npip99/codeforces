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

int dist[5005][5005];

vector<int> dijkstra(vector<vi>& adj, int start)
{
  priority_queue<pair<int,int>> q;
  vector<int> dist(adj.size(), -1);
  dist[start] = 0;
  q.push({0, start});

  while( !q.empty() )
  {
    int i = q.top().second; q.pop();

    for(int edge : adj[i])
      if( dist[edge] == -1 || dist[i] + 1 < dist[edge] )
      {
        dist[edge] = dist[i] + 1;
        q.push({-dist[edge], edge});
      }
  }

  return dist;
}

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int n, m, k;
  cin >> n >> m >> k;
  
  vector<vi> adj(n);
  for( int i = 0; i < m; ++i ) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  int worst = 0;
  for( int i = 0; i < n; ++i ) {
    vector<int> res = dijkstra(adj, i);
    for(int j : res) {
      worst = max(worst, j);
    }
  }
  
  if(worst <= n - k) {
    cout << n << "\n";
    for( int i = 1; i <= n; ++i ) {
      cout << i << " ";
    }
    cout << "\n";
  } else {
    cout << "0\n";
  }
  
  return 0;
}
