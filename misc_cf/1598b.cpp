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
    vector<vector<bool>> days(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            int a;
            cin >> a;
            days[i].push_back(a == 1);
        }
    }
    bool works = false;
    for(int day1 = 0; day1 < 5; day1++) {
        for(int day2 = day1+1; day2 < 5 && !works; day2++) {
            int can_do_day1 = 0;
            int can_do_day2 = 0;
            int can_do_both = 0;
            int can_do_neither = 0;
            for(int i = 0; i < n; i++) {
                if (days[i][day1] && days[i][day2]) {
                    can_do_both++;
                } else if (days[i][day1]) {
                    can_do_day1++;
                } else if (days[i][day2]) {
                    can_do_day2++;
                } else {
                    can_do_neither++;
                }
            }
            if (can_do_neither == 0
             && abs(can_do_day1 - can_do_day2) <= can_do_both) {
                 works = true;
            }
        }
    }
    cout << (works ? "YES" : "NO") << endl;
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
