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

#define mn 100005

int arr[3*mn];
int closeleft[3*mn];
int closeright[3*mn];
int stack[3*mn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  for( int i = 0; i < n; ++i ) {
    cin >> arr[i];
    arr[i+2*n] = arr[i+n] = arr[i];
  }
  
  int stacksize = 0;
  for( int i = 0; i < 3*n; ++i ) {
    while( stacksize > 0 && arr[stack[stacksize-1]] >= arr[i] )
      stacksize--;
    if( stacksize == 0 )
      closeleft[i] = -1;
    else {
      closeleft[i] = stack[stacksize-1];
    }
    stack[stacksize++] = i;
  }
  
  stacksize = 0;
  for( int i = 3*n - 1; i >= 0; --i ) {
    while( stacksize > 0 && arr[stack[stacksize-1]] >= arr[i] )
      stacksize--;
    if( stacksize == 0 )
      closeright[i] = -1;
    else {
      closeright[i] = stack[stacksize-1];
    }
    stack[stacksize++] = i;
  }
  
  int bestlen = 4*n;
  int bestl = -1;
  int besti = -1;
  int bestr = -1;
  for( int i = n; i < 2*n; ++i ) {
    if( closeright[i] != -1 && closeleft[i] != -1 ) {
      if( closeright[i] - closeleft[i] < bestlen ) {
        bestlen = closeright[i] - closeleft[i];
        bestl = closeleft[i] % n + 1;
        besti = i % n + 1;
        bestr = closeright[i] % n + 1;
      }
    }
  }
  
  cout << bestl << " " << besti << " " << bestr << "\n";
  
  return 0;
}
