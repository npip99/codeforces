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

vector<bool>::reference getref(vector<bool>& arr, int i, bool is_not, int C) {
    if (is_not) {
        return arr.at(C-i);
    } else {
        return arr.at(C+i);
    }
}

bool getval(vector<bool>& arr, int i, bool is_not, int C) {
    return is_not ? !getref(arr, i, is_not, C) : getref(arr, i, is_not, C);
}

void main_ans(int test_case) {
    int n;
    cin >> n;
    string as, bs;
    cin >> as >> bs;
    vector<bool> a(n), b(n);
    for(int i = 0; i < n; i++) {
        a[i] = as[i] == '1';
        b[i] = bs[i] == '1';
    }

    vector<int> prefixes;

    bool is_not = false;
    int C = 0;
    for(int i = n-1; i >= 0; i--) {
        if (getval(a, i, is_not, C) == b[i]) {
            continue;
        }
        // If it's already equal, we need to flip it in advance
        if (getval(a, 0, is_not, C) == b[i]) {
            getref(a, 0, is_not, C) = !getref(a, 0, is_not, C);
            prefixes.push_back(0+1);
        }
        C += is_not ? -i : i;
        is_not = !is_not;
        prefixes.push_back(i+1);
    }

    cout << prefixes.size();
    for(int i : prefixes) {
        cout << " " << i;
    }
    cout << endl;
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
