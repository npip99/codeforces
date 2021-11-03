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
typedef map<string, int> msi;
typedef map<string, string> mss;

#define trace(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod int(1e9+7)

#define MN 2005

int dp[MN][MN]; // dp[end][len] = seqs that end in "end" and have length <= "len"

int main()
{
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
    dp[i][1] = 1;

  for(int end = 1; end <= n; end++)
    for(int prev = 1; prev <= end; prev++)
      if( end % prev == 0 )
        for(int len = 2; len <= k; len++)
          dp[end][len] = (dp[end][len] + dp[prev][len-1]) % mod;

  int ans = 0;
  for(int i = 1; i <= n; i++)
    ans = (ans + dp[i][k]) % mod;

  cout << ans << endl;

  return 0;
}
