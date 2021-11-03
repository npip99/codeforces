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

void main_ans(int test_case) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    set<int> stuff_in_a;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        stuff_in_a.insert(a[i]);
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < m; i++) {
        if (stuff_in_a.count(b[i])) {
            cout << "YES" << endl;
            cout << 1 << " " << b[i] << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
