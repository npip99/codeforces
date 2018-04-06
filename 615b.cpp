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

vector<int> adj[100005];
int lens[100005];

int main()
{
  int n, m;
  cin >> n >> m;
  
  for( int i = 0; i < m; ++i ) {
    int a, b;
    cin >> a >> b; a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  ll best = 0;
  for( int i = 0; i < n; ++i ) {
    lens[i] = 1;
    for( int edge : adj[i] ) {
      lens[i] = max(lens[i], lens[edge] + 1);
    }
    best = max(best, lens[i] * (ll)adj[i].size());
  }
  
  cout << best << endl;
  
  return 0;
}
