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
    vector<string> strings(n);
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    string s;
    cin >> s;

    map<string, tuple<int, int, int>> segments;
    for(int si = 0; si < n; si++) {
        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j <= i + 2 && j < m; j++) {
                string sub = strings[si].substr(i, j+1 - i);
                if (segments.count(sub) == 0) {
                    segments[sub] = {i+1, j+1, si+1};
                }
            }
        }
    }

    vector<bool> reachable(m+1, false);
    reachable[m] = true;
    reachable[m-1] = false;
    for(int i = m-2; i >= 0; i--) {
        if (reachable[i+2] && segments.count(s.substr(i, 2))) {
            reachable[i] = true;
        } else if (i + 3 <= m && reachable[i+3] && segments.count(s.substr(i, 3))) {
            reachable[i] = true;
        }
    }

    if (reachable[0]) {
        vector<tuple<int, int, int>> ans_segments;

        int i = 0;
        while (i != m) {
            if (reachable[i+2]) {
                ans_segments.push_back(segments[s.substr(i, 2)]);
                i += 2;
            } else if (i + 3 <= m && reachable[i+3]) {
                ans_segments.push_back(segments[s.substr(i, 3)]);
                i += 3;
            }
        }

        int k = ans_segments.size();
        cout << k << endl;
        for(int j = 0; j < k; j++) {
            cout << get<0>(ans_segments[j]) << " " << get<1>(ans_segments[j]) << " " << get<2>(ans_segments[j]) << endl;
        }
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
