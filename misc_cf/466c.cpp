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
#define trace(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL

#define MN int(5*1e5+5)
int arr[MN];
ll prefix[MN];
int starting[MN];
int ending[MN];

int main()
{
	int n;
	ll sum = 0;
	cin >> n;
	rep(i, 0, n)
		cin >> arr[i], sum += arr[i], prefix[i] = prefix[i-1] + arr[i];
	if( sum % 3 != 0 )
	{
		cout << "0\n";
		return 0;
	}
	sum /= 3;
	rep(i, 0, n)
	{
		if( prefix[i] == sum )
			starting[i] = 1;
		if( prefix[i] == 2 * sum )
			ending[i] = 1;
		ending[i] += ending[i-1];
	}
	
	ll ans = 0;
	rep(i, 0, n - 2)
	{
		if( starting[i] )
		{
			ans += ending[n-2] - ending[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
