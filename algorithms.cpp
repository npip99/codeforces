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
typedef map<string, int> msi;
typedef map<string, string> mss;

#define trace(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL

int N = 10000;

/* MERGE-FIND */
vii mf(N); // Set to {0, 1, 2, ..., N-1}
// ii as {parent, rank}

int find(int i)
{
    if (mf[i].first != i)
        mf[i].first = find(mf[i].first);
    return mf[i].first;
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (mf[x].second < mf[y].second)
        mf[x].first = y;
    else if (mf[x].second > mf[y].second)
        mf[y].first = x;
    else
    {
        mf[y].first = x;
        mf[x].second++;
    }
}

/* GRAPH THEORY */
vector<int> dijkstra(vector<vii> adj)
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

pair<int,vii> kruskals(vector<pair<int,ii>> edges)
{
  pair<int,vii> ans;

  for( int i = 0; i < N; i++ )
    mf[i].first = i;

  sort(edges.begin(), edges.end());
  for( auto it = edges.begin(); it != edges.end(); ++it )
  {
    int u = it->second.first;
    int v = it->second.second;

    u = find(u);
    v = find(v);

    if( u != v )
    {
      ans.second.push_back({it->second.first, it->second.second});
      // (it->second.first, it->second.second) is in the MST
      ans.first += it->first;
      merge(u, v);
    }
  }
  return ans;
}

/* FENWICK TREE */
vector<ll> fenwick(N);

void f_update(int index, int val)
{
  for(index++; uint(index) < fenwick.size(); index += index & -index)
    fenwick[index] += val;
}

ll f_sum(int start, int end = -1)
{
  if( end < 0 )
  {
    end = start;
    start = 0;
  }
  ll ret = 0;
  for(end++; end > 0; end -= end & -end)
    ret += fenwick[end];
  for(; start > 0; start -= start & -start)
    ret -= fenwick[start];
  return ret;
}

/* SEGMENT TREE */
vector<ll> segtree(1 << (int(ceil(log2(N))) + 1));

void update(int ind, int val, int s = 0, int e = -1, int index = 0)
{
  if( e < 0 )
    e = segtree.size() - 1;

  if( e < ind || ind < s )
    return;

  segtree[index] += val;
  if( s != e )
  {
    int mid = s + (e - s) / 2;
    update(ind, val, s, mid, 2*index + 1);
    update(ind, val, mid + 1, e, 2*index + 2);
  }
}

ll sum(int start, int end = -1, int s = 0, int e = -1, int index = 0)
{
  if( end == -1 )
  {
    end = start;
    start = 0;
  }
  if( e < 0 )
    e = segtree.size() - 1;

  if( start <= s && e <= end )
    return segtree[index];
  if( e < start || end < s )
    return 0;

  int mid = s + (e - s) / 2;
  return sum(start, end, s, mid, 2*index + 1) + sum(start, end, mid + 1, e, 2*index + 2);
}

int main()
{
	return 0;
}
