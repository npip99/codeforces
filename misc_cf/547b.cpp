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

#define MN 200005

int arr[MN];
int stack[MN];
int l[MN]; // left
int r[MN]; // right
int ans[MN];

int main()
{
  int n;
  cin >> n;
  
  int top = -1;
  for( int i = 0; i < n; ++i ) {
    cin >> arr[i];
    while( top >= 0 && arr[stack[top]] >= arr[i] )
      top--;
    l[i] = top >= 0 ? stack[top] : -1;
    stack[++top] = i;
  }
  
  top = -1;
  for( int i = n - 1; i >= 0; --i ) {
    while( top >= 0 && arr[stack[top]] >= arr[i] )
      top--;
    r[i] = top >= 0 ? stack[top] : n;
    stack[++top] = i;
  }
  
  for( int i = 0; i < n; ++i ) {
    int len = r[i] - l[i] - 1;
    ans[len] = max(ans[len], arr[i]);
  }
  
  for( int i = n - 1; i > 0; --i ) {
    ans[i] = max(ans[i], ans[i+1]);
  }
  
  for( int i = 1; i <= n; ++i ) {
    cout << ans[i] << " ";
  }
  
  return 0;
}
