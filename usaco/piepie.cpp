// INPUT
// N D
// B_1 E_1 <- Bessie's
// ...
// B_{N} E_{N}
// B2_1 E2_1 <- Elsie's
// ...
// B2_{N} E2_{N}

// If E gets a pie P from B, E gives a pie Q to B. P_e <= Q_e <= P_e + D. Repeats until P_e = 0.

// OUTPUT
// Min # of Pies gifted if Bessie gives Pie #i to Elsie. If no valid seq, -1

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

ii b[100000];
ii e[100000];

int segtree[200005];
int segsize = -1;

void update(int ind, int val, int s = 0, int e = -1, int index = 0)
{
  if( e < 0 )
    e = segsize;

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
    e = segsize;

  if( start <= s && e <= end )
    return segtree[index];
  if( e < start || end < s )
    return 0;

  int mid = s + (e - s) / 2;
  return sum(start, end, s, mid, 2*index + 1) + sum(start, end, mid + 1, e, 2*index + 2);
}

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int n, d;
  cin >> n >> d;
  
  for( int i = 0; i < n; ++i ) {
    cin >> b[i].first >> b[i].second;
  }
  for( int i = 0; i < n; ++i ) {
    cin >> e[i].first >> e[i].second;
  }
  
  
  
  return 0;
}
