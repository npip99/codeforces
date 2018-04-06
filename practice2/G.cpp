#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>

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
  vector<vector<int>> nums(n, vector<int>());
  for( int i = 0; i < n; ++i ) {
    for( int j = 1; j <= n; ++j ) {
      if( i != j - 1 )
        nums[i].push_back(j);
    }
  }
  
  int cur = 1;
  
  string prev = "1 1 0\n";
  while( true ) {
    if( nums[cur-1].size() == 0 )
      break;
    int num = nums[cur-1].back();
    nums[cur-1].pop_back();
    cout << prev;
    prev = to_string(num) + " " + to_string(num) + " " + to_string(cur) + "\n";
    cur = num;
  }
  cout << "0 1 " << (cur+1) << "\n";
  
  return 0;
}
