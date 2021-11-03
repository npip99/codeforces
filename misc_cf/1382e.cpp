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

/*
-rw-r--r--   1 npip99  staff   1.5K Nov  2 21:08 1382a.cpp
-rw-r--r--   1 npip99  staff   2.1K Nov  2 21:21 1382b.cpp
-rw-r--r--   1 npip99  staff   1.0K Nov  2 21:04 1382c1.cpp
-rw-r--r--   1 npip99  staff   2.1K Nov  2 21:58 1382c2.cpp
-rw-r--r--   1 npip99  staff   2.0K Nov  2 22:20 1382d.cpp, 10 minutes to make n^2 instead of n^3 memo
-rw-r--r--   1 npip99  staff   3.1K Nov  2 23:03 1382e.cpp
*/

void main_ans(int test_case) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> b(n);
    map<int, int> freqs;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        freqs[b[i]]++;
    }

    int orig_x = x;
    int orig_y = y;

    priority_queue<pair<int, int>> pq;
    for(auto val : freqs) {
        pq.push({val.second, val.first});
    }

    int unused_color = -1;
    for(int i = 1; i <= n+1; i++) {
        if (freqs[i] == 0) {
            unused_color = i;
            break;
        }
    }

    map<int, int> correct;
    while(pq.size() > 0 && x > 0 && y > 0) {
        pair<int, int> most = pq.top(); pq.pop();
        int val = most.second;

        // Update freq
        most.first--;
        if (most.first > 0) {
            pq.push({most.first, most.second});
        }

        correct[most.second]++;
        x--;
        y--;
    }

    map<int, vector<int>> incorrect_swaps;
    while (pq.size() >= 2 && y > 0) {
        pair<int, int> stack1 = pq.top(); pq.pop();
        pair<int, int> stack2 = pq.top(); pq.pop();

        incorrect_swaps[stack1.second].push_back(stack2.second);
        incorrect_swaps[stack2.second].push_back(stack1.second);

        stack1.first--;
        if (stack1.first > 0) {
            pq.push({stack1.first, stack1.second});
        }
        stack2.first--;
        if (stack2.first > 0) {
            pq.push({stack2.first, stack2.second});
        }

        // Counts as two wrong multis
        y--;
        if (y > 0) {
            y--;
        }
    }

    if (x == 0 && y == 0) {
        cout << "YES" << endl;
        orig_y -= orig_x;
        for(int i = 0; i < n; i++) {
            if (correct[b[i]] > 0) {
                correct[b[i]]--;
                cout << b[i] << " ";
            } else if (orig_y > 0 && incorrect_swaps[b[i]].size() > 0) {
                int other = incorrect_swaps[b[i]].back();
                incorrect_swaps[b[i]].pop_back();
                cout << other << " ";
                orig_y--;
            } else {
                cout << unused_color << " ";
            }
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
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
