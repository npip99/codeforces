#include <iostream>
#include <queue>
#include <ctime>
#include "fibheap.h"

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj)
{
  priority_queue<pair<int,int>> q;
  vector<int> dist(adj.size(), -1);
  dist[0] = 0;
  q.push({0, 0});

  while( !q.empty() )
  {
    int i = q.top().second; q.pop();

    for(pair<int,int>& edge : adj[i])
      if( dist[edge.first] == -1 || dist[i] + edge.second < dist[edge.first] )
      {
        dist[edge.first] = dist[i] + edge.second;
        q.push({-dist[edge.first], edge.first});
      }
  }

  return dist;
}

vector<int> fibonacci_dijkstra(vector<vector<pair<int, int>>>& adj)
{
  fibonacci_queue<pair<int,int>> q;
  vector<int> dist(adj.size(), -1);
  vector<void*> nodes(adj.size(), NULL);
  dist[0] = 0;
  nodes[0] = q.insert({0, 0});

  while( q.size() > 0 )
  {
    int i = q.find_min().second; q.remove_min();

    for(pair<int,int>& edge : adj[i])
      if( dist[edge.first] == -1 || dist[i] + edge.second < dist[edge.first] )
      {
        dist[edge.first] = dist[i] + edge.second;
        if( nodes[edge.first] == NULL ) {
          nodes[edge.first] = q.insert({dist[edge.first], edge.first});
        } else {
          q.decrease_key(nodes[edge.first], {dist[edge.first], edge.first});
        }
      }
  }

  return dist;
}

// https://stackoverflow.com/questions/26237419/faster-than-rand
static unsigned int g_seed;

// Used to seed the generator.           
inline void fast_srand(int seed) {
    g_seed = seed;
}

// Compute a pseudorandom integer.
// Output value in range [0, 32767]
inline int fast_rand(void) {
    g_seed = (214013*g_seed+2531011);
    return (g_seed>>16)&0x7FFF;
}

vector<vector<pair<int, int>>> generate_graph(int n, double density) {
  auto ret = vector<vector<pair<int, int>>>(n);
  for( int i = 0; i < n * (n-1) * density; ++i ) {
    int a = fast_rand() % n;
    int b = fast_rand() % n;
    ret[a].push_back({b, fast_rand() % 100 + 1});
    ret[b].push_back({a, fast_rand() % 100 + 1});
  }
  return ret;
}

pair<double, double> time_check(int n, double density) {
  pair<double, double> ret;
  
  auto graph = generate_graph(n, density);
  cout << graph.size() << endl;
  
  clock_t t1 = clock();
  vector<int> ans = dijkstra(graph);
  clock_t t2 = clock();
  ret.first = (t2-t1) / (double)CLOCKS_PER_SEC;
  
  t1 = clock();
  vector<int> ans2 = fibonacci_dijkstra(graph);
  t2 = clock();
  ret.second = (t2-t1) / (double)CLOCKS_PER_SEC;
  
  for( int i = 0; i < n; ++i ) {
    if( ans[i] != ans2[i] ) {
      return {-1, -1};
    }
  }
  
  return ret;
}

int main() {
  fast_srand(1234);
  pair<double, double> ret = time_check(10000, 0.8);
  cout << ret.first << " " << ret.second << endl;
  
  return 0;
}