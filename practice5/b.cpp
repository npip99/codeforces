#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <math.h>

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

double sw[105][3];

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  double n, X, v;
  cin >> n >> X >> v;
  
  for( int i = 0; i < n; ++i ) {
    cin >> sw[i][0] >> sw[i][1] >> sw[i][2];
  }
  
  double pi = 2*acos(0);
  
  double lo = -pi/2;
  double hi = pi/2;
  
  double prevt = 100;
  double t = 0;
  while( hi - lo > 0.1 || (t-prevt > 0 ? t-prevt : -(t-prevt)) > 0.0001 ) {
    if( hi - lo <= 0.1 && t > 2*X / v ) {
      break;
    }
    
    double mid = (hi + lo)/2;
    
    double y = 0.0;
    double x = 0.0;
    prevt = t;
    t = 0.0;
    for( int i = 0; i < n; ++i ) {
      double tt = (sw[i][0] - x)/(v*cos(mid));
      t += tt;
      y += tt*v*sin(mid);
      x = sw[i][0];
      
      double rtime = (sw[i][1] - sw[i][0])/(v*cos(mid));
      t += rtime;
      y += rtime*(v*sin(mid) + sw[i][2]); 
      x = sw[i][1];
    }
    
    double tt = (X - x)/(v*cos(mid));
    t += tt;
    y += tt*v*sin(mid);
    x = X;
    
    if( y < 0 ) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  
  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(3);
  if( t > 2 * X / v )
    cout << "Too hard\n";
  else
    cout << t << "\n";
  
  return 0;
}
