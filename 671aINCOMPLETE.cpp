#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
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

#define mn 100005

double x[mn];
double y[mn];
double sava[mn];
double savb[mn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  double ax, ay, bx, by, tx, ty, n;
  cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
  
  double besta = infl;
  double bestb = infl;
  double best = infl;
  double ans = 0;
  for( int i = 0; i < n; ++i ) {
    cin >> x[i] >> y[i];
    ans += 2*sqrt((tx - x[i])*(tx - x[i]) + (ty - y[i])*(ty - y[i]));
    sava[i] = sqrt((ax - x[i])*(ax - x[i]) + (ay - y[i])*(ay - y[i])) - sqrt((tx - x[i])*(tx - x[i]) + (ty - y[i])*(ty - y[i]));
    savb[i] = sqrt((bx - x[i])*(bx - x[i]) + (by - y[i])*(by - y[i])) - sqrt((tx - x[i])*(tx - x[i]) + (ty - y[i])*(ty - y[i]));
    best = min({besta + savb[i], bestb + sava[i], best});
    besta = min(besta, sava[i]);
    bestb = min(bestb, savb[i]);
  }
  
  cout.precision(15);
  cout << (best + ans) << endl;
  
  return 0;
}
