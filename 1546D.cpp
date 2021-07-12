#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>
#include <stdio.h>      /* printf */
#include <stdlib.h>
#include <queue>

#ifdef SHOW_DEBUG
#define dbg(a, ...) printf("DEBUG: " a "\n", ##__VA_ARGS__)
#else
#define dbg(...) ((void*)(0))
#endif

using namespace std;
typedef long long ll;
template<typename A, typename B>
using hmap = unordered_map<A, B>;
typedef tuple<int, int> ii;
typedef tuple<ll, ll> lii;
#define PI 3.14159265358979323846
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL

#define M (998'244'353L)

ll mod_inverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        ll q = a / m;
        ll t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;
    return x;
}

ll fact(ll a) {
    ll ret = 1;
    for(ll i = 1; i <= a; i++) {
        ret *= i;
        ret %= M;
    }
    return ret;
}

ll c(ll a, ll b) {
    ll ans = 1;
    ll numerator = fact(a);
    ll denominator = (fact(b) * fact(a-b)) % M;
    return (numerator * mod_inverse(denominator, M)) % M;
}

int main() {
    int T;
    cin >> T;
    for(int test = 0; test < T; test++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<bool> board(n);
        for(int i = 0; i < n; i++) {
            board[i] = (s[i] == '1');
        }

        vector<char> ans;
        for(int i = 0; i < n; i++) {
            if (board[i]) {
                if (ans.size() > 0 && ans.back() == 'B') {
                    ans.back() = 'A';
                } else {
                    ans.push_back('B');
                }
            } else {
                ans.push_back('0');
            }
        }

        int As = 0;
        int Zeros = 0;
        for(char c : ans) {
            if (c == 'A') {
                As++;
            }
            if (c == '0') {
                Zeros++;
            }
        }

        cout << c(As+Zeros, Zeros) << endl;
    }
    return 0;
}
