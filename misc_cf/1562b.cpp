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

bool is_composite(vector<ll>& v) {
    int ans = 0;
    int coef = 1;
    for(int i = v.size()-1; i >= 0; i--) {
        ans += coef * v[i];
        coef *= 10;
    }

    for(int i = 2; i*i <= ans; i++) {
        if (ans % i == 0) {
            return true;
        }
    }
    return false;
}

void solve(vector<ll> digs) {
    for(int num : {1, 4, 6, 8, 9}) {
        for(int dig : digs) {
            if (dig == num) {
                std::cout << "1\n" << num << endl;
                return;
            }
        }
    }

    for(int num : {2, 5}) {
        for(int i = 1; i < digs.size(); i++) {
            if (digs[i] == num) {
                std::cout << "2\n" << digs[i-1] << num << endl;
                return;
            }
        }
    }

    for(int num : {3, 7}) {
        int cnt = 0;
        for(int dig : digs) {
            if (dig == num) cnt++;
        }
        if (cnt >= 2) {
            std::cout << "2\n" << num << num << endl;
            return;
        }
    }

    int one_cnt = 0;
    for(int dig : digs) {
        if (dig == 1) one_cnt++;
    }

    if (one_cnt >= 3) {
        if (digs[0] == 2 || digs[0] == 5) {
            std::cout << "2\n" << digs[0] << 1 << endl;
            return;
        }

        std::cout << "3\n111\n";
        return;
    } else {
        vector<ll> best_answer = digs;
        for(int i = 0; i < 32; i++) {
            vector<ll> new_digs;
            for(int j = 0; j < digs.size(); j++) {
                if ( ((i >> j) & 1) == 1 ) {
                    new_digs.push_back(digs[j]);
                }
            }

            if (is_composite(new_digs)) {
                if (new_digs.size() <= best_answer.size()) {
                    best_answer = new_digs;
                }
            }
        }

        std::cout << best_answer.size() << endl;
        for(int dig : best_answer) {
            std::cout << dig;
        }
        std::cout << endl;
        return;
    }
}

int main() {
    ll tt;
    cin >> tt;
    for(ll t = 0; t < tt; t++) {
        ll k;
        cin >> k;
        string s;
        cin >> s;
        vector<ll> digs;
        for(int i = 0; i < s.size(); i++) {
            digs.push_back(s[i] - '0');
        }
        solve(digs);
    }
}
