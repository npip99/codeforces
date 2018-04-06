#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<ii[3]> triangles(n);
  for( int i = 0; i < n; ++i ) {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    triangles[i][0] = {x1,y1};
    triangles[i][1] = {x2,y2};
    triangles[i][2] = {x3,y3};
  }
  
  return 0;
}
