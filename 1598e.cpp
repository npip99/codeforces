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
#define TEST_CASES false

int staircase_length(vector<vector<bool>>& g, int r, int c, pair<int, int> f, pair<int, int> s){
    int i=0;
    try{
    for(;i==0||g.at(r).at(c);)
        r+=(i%2?f:s).first,
        c+=((i++)%2?f:s).second;
    }catch(...){}
    return i;
}

void main_ans(int test_case) {
    ll n, m, q;
    cin >> n >> m >> q;
    ll ans = 0;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            // 2*min+1 is len of staircase,
            // *2 for two types of staircase,
            // -1 for the double-counted singleton staircase
            ans += 2*(2*min(r, c)+1)-1;
            // Can go an extra distance in only one of the directions
            if (r != c) {
                ans++;
            }
        }
    }
    vector<vector<bool>> grid(n, vector<bool>(m, true));
    for(int qry = 0; qry < q; qry++) {
        ll r, c;
        cin >> r >> c;
        r--, c--;
        int staircases_made = staircase_length(grid, r, c, { 0,  1}, { 1,  0})
                            * staircase_length(grid, r, c, {-1,  0}, { 0, -1})
                            + staircase_length(grid, r, c, { 1,  0}, { 0,  1})
                            * staircase_length(grid, r, c, { 0, -1}, {-1,  0})
                            - 1;
        grid[r][c] = !grid[r][c];
        ans += grid[r][c] ? staircases_made : -staircases_made;
        cout << ans << endl;
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
