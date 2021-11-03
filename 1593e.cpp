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

void main_ans(int test_case) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph(n);
    vector<bool> exists(n, true);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    priority_queue<pair<int, int>> pq;
    vector<int> neighbors(n);
    for(int i = 0; i < n; i++) {
        neighbors[i] = graph[i].size();
        pq.push({-neighbors[i], i});
    }
    for(int opcnt = 0; opcnt < k; opcnt++) {
        if (pq.size() == 0) {
            break;
        }
        vector<int> leaves;
        while(pq.size() > 0) {
            pair<int, int> p = pq.top();
            // Skip nonexistant vertices
            if (!exists[p.second]) {
                pq.pop();
                continue;
            }
            // While is a leaf,
            if (neighbors[p.second] <= 1) {
                pq.pop();
                if (neighbors[p.second] == 0) {
                    exists[p.second] = false;
                } else {
                    leaves.push_back(p.second);
                }
            } else {
                break;
            }
        }
        for(int leaf : leaves) {
            // Skip nonexistant vertices
            if (!exists[leaf]) {
                continue;
            }
            // Remove everything connected to this vertex
            for(int neighbor : graph[leaf]) {
                if (exists[neighbor]) {
                    neighbors[neighbor]--;
                    // Push updated vertex to the pq
                    pq.push({-neighbors[neighbor], neighbor});
                }
            }
            // Mark as visited
            exists[leaf] = false;
        }
    }
    int remaining = 0;
    for(bool exist : exists) {
        if (exist) {
            remaining++;
        }
    }
    cout << remaining << endl;
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
