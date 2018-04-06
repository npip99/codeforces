#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef set<int> si;
typedef unordered_map<int, int> mii;
typedef unordered_map<string, int> msi;
typedef unordered_map<string, string> mss;

#define err(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod int(1e9+7)

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int n;
  cin >> n;
  unordered_map<int, ii> vals;
  vals.reserve(2*n);
  
  for( int i = 0; i < n; ++i ) {
    int f, b;
    cin >> f >> b;
    vals[f].first++;
    if( f != b ) {
      vals[b].second++;
    }
  }
  
  int best = n+1;
  for( auto& i : vals ) {
    if( i.second.first + i.second.second >= (n+1)/2 ) {
      best = min( best, max(0, (n+1)/2 - i.second.first) );
    }
  }
  
  if( best > n ) {
    best = -1;
  }
  cout << best << "\n";
  
  return 0;
}