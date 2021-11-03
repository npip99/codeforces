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

int ans(vector<int> arr, bool print) {
	int moves = 0;
	// Goal array
	vector<int> goal = arr;
	sort(goal.begin(), goal.end());
	// Match the goal
	for(int i = 0; i < arr.size(); i++) {
		// Find the index we need
		int index = i;
		while(arr[index] != goal[i]) {
			index++;
		}
		// Skip a null move
		if (i == index) {
			continue;
		}
		moves++;
		// Print the step we need to do
		int diff = index - i;
		if (print) {
			cout << (i+1) << " " << (index+1) << " " << diff << endl;
		}
		// Make the new post-cycle arr
		vector<int> new_arr = arr;
		for(int j = i; j <= index; j++) {
			new_arr[j] = arr[i + (j-i + diff) % (index-i+1)];
		}
		arr = new_arr;
	}
	return moves;
}

int main()
{
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << ans(arr, false) << endl;
		ans(arr, true);
	}

	return 0;
}
