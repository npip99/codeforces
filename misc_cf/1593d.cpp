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
    vector<int> arr(n);
    bool all_the_same = true;
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] += 1'000'000;
        if (i > 0 && arr[i] != arr[i-1]) {
            all_the_same = false;
        }
        maxi = max(maxi, arr[i]);
    }
    if (all_the_same) {
        cout << -1 << endl;
        return;
    }
    int best_k = 1;
    for(int k = 2; k <= maxi+1; k++) {
        bool possible = true;
        int remains = arr[0] % k;
        for(int a : arr) {
            if (a % k != remains) {
                possible = false;
            }
        }
        if (possible) {
            best_k = k;
        }
    }
    cout << best_k << endl;
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
