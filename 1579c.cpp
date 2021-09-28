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

void ans() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<bool>> grid(n, vector<bool>(m, false));
	vector<vector<bool>> must_be_root(n, vector<bool>(m, false));
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) {
			grid[i][j] = (s[j] == '*');
			// So far, if it's painted, it must be a root
			must_be_root[i][j] = grid[i][j];
		}
	}

	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < m; j++) {
			if (grid[i][j]) {
				// Get the length of a tick whose root is at i, j
				int root_of_length = 0;
				for(int h = 1; h <= i && h <= j && j+h < m; h++) {
					if (!grid[i-h][j-h]) {
						break;
					}
					if (!grid[i-h][j+h]) {
						break;
					}
					root_of_length = h;
				}

				if (root_of_length >= k) {
					// Is a valid root
					for(int h = 1; h <= root_of_length; h++) {
						// Well, these don't have to be a root anymore,
						// Bc another root touches it
						must_be_root[i-h][j-h] = false;
						must_be_root[i-h][j+h] = false;
					}
				} else {
					// Is not a root
					if (must_be_root[i][j]) {
						cout << "NO" << endl;
						return;
					}
				}
			}
		}
	}

	cout << "YES" << endl;
}

int main()
{
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		ans();
	}

	return 0;
}
