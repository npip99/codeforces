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
    map<ll, ll> nums;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        nums[a]++;
        sum += a;
    }
    // 2*Avg must be integer, 2*sum/n must be integer
    if (2*sum % n != 0) {
        cout << 0 << endl;
        return;
    }

    ll ans = 0;
    for(auto& iter : nums) {
        ll a = iter.first;
        // Avg - a = b - Avg
        // b = 2*Avg - a
        ll b = 2*sum / n - a;
        if (nums.count(b)) {
            ll num_As = iter.second;
            ll num_Bs = nums[b];
            if (a == b) {
                num_Bs--;
            }
            // We can pair the As and the Bs
            ans += num_As*num_Bs;
        }
    }

    cout << ans/2 << endl;
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
