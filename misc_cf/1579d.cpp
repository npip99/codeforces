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
#define TEST_CASES true

void main_ans(int test_case) {
	int n;
	cin >> n;
	priority_queue<pair<int, int>> q;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a != 0) {
			q.push({a, i+1});
		}
	}

	int top[2] = {0};
	
	int top_qty[2] = {0};

	int shakes = 0;

	vector<pair<int, int>> ans;

	while (q.size() >= 2) {
		pair<int, int> a = q.top(); q.pop();
		pair<int, int> b = q.top(); q.pop();

		ans.push_back({a.second, b.second});

		a.first--;
		b.first--;

		if (a.first > 0) {
			q.push(a);
		}
		if (b.first > 0) {
			q.push(b);
		}
	}

	cout << ans.size() << endl;
	for(auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
}

int main()
{
	int T = 1;
#if TEST_CASES
	cin >> T;
#endif
	for(int test_case = 1; test_case <= T; test_case++) {
		main_ans(test_case);
	}


	return 0;
}
