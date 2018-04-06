#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[100000];
int dist[100000];
int prv[100000];

int main()
{
  int n, m;
  cin >> n >> m;
  
  for( int i = 0; i < m; i++ ) {
    int a, b, w;
  	cin >> a >> b >> w;
  	a--, b--;
  	adj[a].push_back({b, w});
  	adj[b].push_back({a, w});
  }
  
  for( int i = 0; i < n; ++i ) {
    dist[0] = prv[0] = -1;
  }
  
  dist[0] = 0;
  
  priority_queue<pair<int, int>> verts;
  verts.push({0, 0});
  
  while( verts.size() > 0 ) {
    int u = verts.top().second;
  	verts.pop();
    
  	for( pair<int, int>& v : adj[u] ) {
  	  if( dist[v.first] == -1 || dist[u] + v.second < dist[v.first] ) {
  	    dist[v.first] = dist[u] + v.second;
    		prv[v.first] = u;
    		verts.push({-dist[v.first], v.first});
  	  }
  	}
  }
  
  if( dist[n-1] == -1 ) {
    cout << -1 << endl;
  } else {
    int pos = n-1;
    int k = 0;
  	while( pos != -1 ) {
      dist[k++] = pos + 1;
  	  pos = prv[pos];
  	}
  	for( int i = k - 1; i >= 0; i-- ) {
      cout << dist[i] << " ";
    }
  	cout << endl;
  }
}