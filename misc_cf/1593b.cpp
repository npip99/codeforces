#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#ifdef SHOW_DEBUG
#define dbg(a, ...) printf("DEBUG: " a "\n", ##__VA_ARGS__)
#else
#define dbg(...) ((void*)0)
#endif

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

// 5, 2, Stuff
int dels(vector<int>& digs, int dig1, int dig2) {
    dbg("Start Dig");
    int looking = 1;
    int removals = 0;
    for(int i = 0; i < digs.size(); i++) {
        if (looking == 1) {
            if (digs[i] == dig1) {
                dbg("Dig1 %d found!", digs[i]);
                looking++;
                continue;
            }
        }
        if (looking == 2) {
            if (digs[i] == dig2) {
                dbg("Dig2 %d found!", digs[i]);
                return removals;
            }
        }
        // We should remove this digit
        dbg("Remove Dig %d", digs[i]);
        removals++;
    }
    return digs.size();
}

void main_ans(int test_case) {
    ll n;
    cin >> n;
    vector<int> digs;
    while(n > 0) {
        digs.push_back(n % 10);
        n /= 10;
    }
    int opt1 = dels(digs, 5, 2);
    int opt2 = dels(digs, 0, 5);
    int opt3 = dels(digs, 5, 7);
    int opt4 = dels(digs, 0, 0);
    int ans = min(opt1, min(opt2, min(opt3, opt4)));
    cout << ans << endl;
    // X2Y5Z -> 25Z
    // X5Y0Z -> 50Z
    // X7Y5Z -> 75Z
    // X0Y0Z -> 00Z
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
