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
    int n;
    cin >> n;
    vector<int> stones(n);
    for(int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    // 6 -> Win, take all stones
    // 1 6 -> Lose
    // 5 6 -> Win, take 4 stones
    // 1 5 6 -> Lose, give opponent a win
    // 9 5 6 -> Win, give opponent a 1 5 6 lose
    // 1 9 5 6 -> Lose, give opponent a 9 5 6 win
    // 8 9 5 6 -> Win, give opponent a 1 9 5 6 lose

    vector<bool> first_wins(n);
    first_wins[n-1] = true; // Whoever goes first on the last stone, wins

    for(int i = n-2; i >= 0; i--) {
        if (stones[i] == 1) {
            // No choice but to take the one stone,
            // Making this position an invert of the previous position
            first_wins[i] = !first_wins[i+1];
        } else {
            // If we have 2 or more stones,
            // Then we def win. We either take all stones,
            // Or take all but one stone, we force the situation
            first_wins[i] = true;
        }
    }

    if (first_wins[0]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
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
