#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>

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

int x[505];
int y[505];

int turn(int p, int q, int r)
{
    int cross = (y[q] - y[p]) * (x[r] - x[q]) - (x[q] - x[p]) * (y[r] - y[q]);
 
    if (cross == 0)
      return 0;
    else
      return (cross > 0) ? 1 : -1;
}

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  int sm = 0;
  for( int i = 0; i < n; ++i ) {
    cin >> x[i] >> y[i];
    if( y[i] < y[sm] || (y[i] == y[sm] && x[i] < x[sm]) )
      sm = i;
  }
  
  vector<int> convex;
  int p = sm, q = -1;
  while( q == -1 || p != sm ) {
    convex.push_back(p);
    q = (p+1) % n;
    for( int i = 0; i < n; ++i ) {
      if( turn(p, i, q) == -1 )
        q = i;
    }
    p = q;
  }
  
  double best = infl;
  for( int i = 0; i < convex.size(); ++i ) {
    int next = (i+1) % convex.size();
    double poss = 0;
    for( int j = 0; j < convex.size(); ++j ) {
      if( j == i || j == next )
        continue;
      double x0 = x[convex[j]];
      double y0 = y[convex[j]];
      double x1 = x[convex[i]];
      double y1 = y[convex[i]];
      double x2 = x[convex[next]];
      double y2 = y[convex[next]];
      double dy = y2-y1;
      double dx = x2-x1;
      poss = max(poss,
            abs(dy*x0-dx*y0+x2*y1-y2*x1)/sqrt(dy*dy+dx*dx)
      );
    }
    best = min(best, poss);
  }
  cout << best << "\n";
  
  return 0;
}
