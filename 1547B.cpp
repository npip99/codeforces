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

int main() {
    int T;
    cin >> T;
    for(int test = 0; test < T; test++) {
        string s;
        cin >> s;
        bool failed = false;
        int sz = s.size();
        for(int i = 0; i < sz; i++) {
            int n = sz - i;
            if (s[0] == 'a' + n - 1) {
                s = s.substr(1);
            } else if (s[s.size()-1] == 'a' + n - 1) {
                s = s.substr(0, s.size()-1);
            } else {
                failed = true;
                break;
            }
        }
        cout << (failed ? "NO" : "YES") << endl;
    }
    return 0;
}

