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

vector<pair<int, ii>> adj[1005];
bool vis[1005];

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int n, m, k, s, t;
  cin >> n >> m >> k >> s >> t;
  
  set<int> oldvals;
  
  for( int i = 0; i < m; ++i ) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    adj[a].push_back({b, {c, d}});
    oldvals.insert(c);
    oldvals.insert(d);
  }
  
  set<int> vals;
  map<int, ii> mp;
  int prev = -1;
  for( auto k = oldvals.begin(); k != oldvals.end(); k++ ) {
    if( prev != -1 && prev + 1 < *k ) {
      vals.insert((prev + *k) / 2);
      mp[(prev + *k) / 2] = {prev, *k};
    }
    vals.insert(*k);
    prev = *k;
  }
  
  int ans = 0;
  for(int emp : vals) {
    vector<int> q;
    q.push_back(s);
    
    for( int i = 0; i <= n; ++i ) {
      vis[i] = false;
    }
    
    while(q.size() > 0) {
      int v = q.back();
      q.pop_back();
      if( vis[v] )
        continue;
      vis[v] = true;
      for(auto& child : adj[v]) {
        if( !vis[child.first] && child.second.first <= emp && emp <= child.second.second ) {
          q.push_back(child.first);
        }
      }
    }
    if( vis[t] ) {
      if( oldvals.count(emp) ) {
        ans++;
      } else {
        ans += mp[emp].second - mp[emp].first - 1; 
      }
    }
  }
  
  cout << ans << endl;
  
  
  return 0;
}