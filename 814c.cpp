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

#define trace(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod int(1e9+7)

int ans[26][1505];
int seg[26][1505];
int size[26];

int main()
{
  int n, q;
  string s;
  cin >> n >> s >> q;
  
  for( char c : s )
  {
    c -= 'a';
    if( size[c] > 0 )
      continue;
    bool good = false;
    int len = -1;
    for( int i = 0; i <= n; ++i ) {
      if( good ) {
        len++;
        if( i == n || s[i] - 'a' != c ) {
          seg[c][size[c]++] = len;
          len = 0;
          good = false;
        }
      } else {
        len++;
        if( i == n || s[i] - 'a' == c ) {
          seg[c][size[c]++] = len;
          len = 0;
          good = true;
        }
      }
    }
    if( good )
      size[c]--;
  }
  
  for( int i = 0; i < q; ++i ) {
    int len;
    char c;
    cin >> len >> c;
    c -= 'a';
    int* segs = seg[c];
    if( size[c] <= 2 ) {
      cout << (size[c] == 0 ? len : min(n, len + segs[1])) << endl;
    } else {
      if( !ans[c][len] ) {
        int end = 0;
        int curlen = 0;
        int best = 0;
        int cur = 0;
        for( int i = 1; i < size[c]; i += 2 ) {
          while( curlen <= len ) {
            end += 2;
            cur += segs[end-1];
            if( end == size[c] ) {
              best = max(best, cur);
              break;
            }
            curlen += segs[end];
          }
          if( end == size[c] )
            break;
          best = max(best, cur);
          cur -= segs[i];
          curlen -= segs[i+1];
        }
        ans[c][len] = min(n, len + best);
      }
      cout << ans[c][len] << endl;
    }
  }
  
  return 0;
}