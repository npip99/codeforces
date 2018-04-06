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

#define f first
#define s second

#define err(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod int(1e9+7)

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  pair<double, double> abc[3];
  for( int i = 0; i < 3; ++i ) {
    cin >> abc[i].f >> abc[i].s;
  }
  
  vector<pair<double, double>> pts;
  
  int n;
  double sm, lg;
  cin >> n >> sm;
  lg = sm;
  for( int i = 1; i < n; ++i ) {
    double num;
    cin >> num;
    if( num < sm )
      sm = num;
    if( num > lg )
      lg = num;
  }
  sm /= sqrt((abc[1].f - abc[0].f)*(abc[1].f - abc[0].f)
  + (abc[1].s - abc[0].s)*(abc[1].s - abc[0].s));
  lg /= sqrt((abc[1].f - abc[0].f)*(abc[1].f - abc[0].f)
  + (abc[1].s - abc[0].s)*(abc[1].s - abc[0].s));
  pts.push_back({abc[0].f + (abc[1].f-abc[0].f)*sm, abc[0].s + (abc[1].s-abc[0].s)*sm});
  pts.push_back({abc[0].f + (abc[1].f-abc[0].f)*lg, abc[0].s + (abc[1].s-abc[0].s)*lg});
  
  cin >> n >> sm;
  lg = sm;
  for( int i = 1; i < n; ++i ) {
    double num;
    cin >> num;
    if( num < sm )
      sm = num;
    if( num > lg )
      lg = num;
  }
  sm /= sqrt((abc[2].f - abc[1].f)*(abc[2].f - abc[1].f)
  + (abc[2].s - abc[1].s)*(abc[2].s - abc[1].s));
  lg /= sqrt((abc[2].f - abc[1].f)*(abc[2].f - abc[1].f)
  + (abc[2].s - abc[1].s)*(abc[2].s - abc[1].s));
  pts.push_back({abc[1].f + (abc[2].f-abc[1].f)*sm, abc[1].s + (abc[2].s-abc[1].s)*sm});
  pts.push_back({abc[1].f + (abc[2].f-abc[1].f)*lg, abc[1].s + (abc[2].s-abc[1].s)*lg});
  
  cin >> n >> sm;
  lg = sm;
  for( int i = 1; i < n; ++i ) {
    double num;
    cin >> num;
    if( num < sm )
      sm = num;
    if( num > lg )
      lg = num;
  }
  sm /= sqrt((abc[0].f - abc[2].f)*(abc[0].f - abc[2].f)
  + (abc[0].s - abc[2].s)*(abc[0].s - abc[2].s));
  lg /= sqrt((abc[0].f - abc[2].f)*(abc[0].f - abc[2].f)
  + (abc[0].s - abc[2].s)*(abc[0].s - abc[2].s));
  pts.push_back({abc[2].f + (abc[0].f-abc[2].f)*sm, abc[2].s + (abc[0].s-abc[2].s)*sm});
  pts.push_back({abc[2].f + (abc[0].f-abc[2].f)*lg, abc[2].s + (abc[0].s-abc[2].s)*lg});
  
  double best = 0;
  for( auto pt1 : pts ) {
    for( auto pt2 : pts ) {
      for( auto pt3 : pts) {
        double area = 0;
        area += pt1.f*pt2.s;
        area += pt2.f*pt3.s;
        area += pt3.f*pt1.s;
        area -= pt1.s*pt2.f;
        area -= pt2.s*pt3.f;
        area -= pt3.s*pt1.f;
        area = abs(area)/2;
        best = max(best, area);
      }
    }
  }
  
  cout << best << "\n";
  
  return 0;
}
