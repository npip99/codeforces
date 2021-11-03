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

int x[1000];
double y[1000];

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int n, r;
  cin >> n >> r;
  
  for( int i = 0; i < n; ++i ) {
    cin >> x[i];
  }
  
  for( int i = 0; i < n; ++i ) {
    y[i] = r;
    for( int j = 0; j < i; ++j ) {
      if( abs(x[j] - x[i]) <= 2*r ) {
        y[i] = max(y[i], y[j] + sqrt((2*r)*(2*r) - (x[j] - x[i])*(x[j] - x[i])));
      }
    }
  }
  
  for( int i = 0; i < n; ++i ) {
    cout << y[i] << " ";
  }
  
  return 0;
}
