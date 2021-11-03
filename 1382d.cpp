#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <unordered_map>

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

map<tuple<int, int, int>, bool> memo;
bool dp(vector<int>& arr, int i, int rema, int remb) {
    if (rema < 0 || remb < 0) {
        return false;
    }
    if (i == arr.size()) {
        return rema == 0 && remb == 0;
    }
    if (memo.count({i, rema, remb})) {
        return memo[{i, rema, remb}];
    }
    int region = arr[i];
    return memo[{i, rema, remb}] = (dp(arr, i+1, rema - region, remb) || dp(arr, i+1, rema, remb - region));
}

void main_ans(int test_case) {
    int n;
    cin >> n;
    vector<int> p(2*n);
    for(int i = 0; i < 2*n; i++) {
        cin >> p[i];
    }

    vector<int> regions;
    int pmax = p[0];
    int cumulative = 1;
    for(int i = 1; i < 2*n; i++) {
        if (p[i] > pmax) {
            regions.push_back(cumulative);
            cumulative = 1;
            pmax = p[i];
        } else {
            cumulative++;
        }
    }
    regions.push_back(cumulative);

    memo.clear();
    bool ans = dp(regions, 0, n, n);
    
    cout << (ans ? "YES" : "NO") << endl;
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
