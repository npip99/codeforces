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

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define rng(x) (x).begin(),(x).end()
#define trace(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL

int main()
{
  int n, m;
  cin >> n >> m;
  vi arr(m);
  rep(i, 0, m)
    cin >> arr[i];
  sort(rng(arr));
  int best = inf;
  rep(i, n - 1, m)
    best = min(best, abs(arr[i] - arr[i-n+1]));
  cout << best << endl;
	return 0;
}
