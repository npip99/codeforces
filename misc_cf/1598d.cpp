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
    map<int, int> topfreq;
    map<int, int> difffreq;
    vector<ii> probs(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        topfreq[a]++;
        difffreq[b]++;
        probs[i] = {a, b};
    }
    ll ans = 0;
    for(ii prob : probs) {
        ans += (topfreq[prob.first] - 1) * (ll)(difffreq[prob.second] - 1);
    }
    cout << ((ll)n)*(n-1)*(n-2)/6 - ans << endl;
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
