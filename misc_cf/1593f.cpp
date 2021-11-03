#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <unordered_map>
#include <optional>

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

vector<int> num;
int A;
int B;

map<tuple<int, int, int, int>, ll> memo;
ll ans(int index, int u, int v, int r) {
    // Return only if all the reds are met
    if (index == num.size()) {
        if (r == 0 && u == 0 && v == 0) {
            return 0;
        } else {
            return -1;
        }
    }
    // Return if an impossible request of reds is made
    if (r < 0) {
        return -1;
    }

    tuple<int, int, int, int> entry = {index, u, v, r};
    if (memo.count(entry)) {
        return memo[entry];
    }
    int dig = num[index];
    index++;

    // If this new card is red
    for(int i = 0; i < A; i++) {
        if ( (i * 10 + dig) % A == u ) {
            ll ret = ans(index, i, v, r-1);
            if (ret != -1) {
                ret |= (1L << (index-1));
                //dbg("%d %d %d %d is possible, via %x red ans(%d, %d, %d, %d)", index-1, u, v, r, ret, index, i, v, r-1);
                return memo[entry] = ret;
            }
        }
    }

    // If this new card is black
    for(int i = 0; i < B; i++) {
        if ( (i * 10 + dig) % B == v ) {
            ll ret = ans(index, u, i, r);
            if (ret != -1) {
                //dbg("%d %d %d %d is possible, via %x black ans(%d, %d, %d, %d)", index-1, u, v, r, ret, index, u, i, r);
                return memo[entry] = ret;
            }
        }
    }

    // Otherwise, it's not possible
    return memo[entry] = -1;
}

void main_ans(int test_case) {
    int n;
    cin >> n >> A >> B;
    string s;
    cin >> s;
    num.clear();
    memo.clear();
    for(int i = s.size() - 1; i >= 0; i--) {
        num.push_back(s[i] - '0');
    }
    ll best = -1;
    double prev_best_weight = 100000000.0;
    for(int i = 1; i < s.size(); i++) {
        ll ret = ans(0, 0, 0, i);
        if (ret != -1) {
            double weight = abs(s.size() / 2.0 - i);
            if (weight < prev_best_weight) {
                prev_best_weight = weight;
                best = ret;
            }
        }
    }
    if (best != -1) {
        for(int i = num.size() - 1; i >= 0; i--) {
            cout << ((best >> i)&1 ? "R" : "B");
        }
        cout << endl;
    } else {
        cout << -1 << endl;
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
