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

char arr[1005];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string str;
  cin >> str;
  
  for( int i = 0; i < str.length(); i++ )
    arr[i] = str[i];
  
  sort(arr, arr+str.length());
  
  for( int i = 0; i < str.length(); i++ ) {
    if( arr[i] == str[i] )
      continue;
    else {
      char* loc = arr+i+1;
      while( *loc != str[i] )
        loc++;
      if( *loc > arr[i] ) {
        cout << int(loc-arr+1) << " " << (i+1) << "\n";
      } else {
        cout << (i+1) << " " << int(loc-arr+1) << "\n";
      }
      *loc = arr[i];
    }
  }
  
  return 0;
}
