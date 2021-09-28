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
#define mod int(1e9+7)

#define MN 0

int main()
{
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		string s;
		cin >> s;
		int freq[3] = {0};
		for(char c : s) {
			freq[c-'A']++;
		}
		if (freq[0] + freq[2] == freq[1]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
