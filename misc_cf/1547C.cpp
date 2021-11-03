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
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(m);
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }

        int ai = 0;
        int bi = 0;

        bool failed = false;
        vector<int> ans;

        int filelen = k;
        for(int i = 0; i < n + m; i++) {
            if (ai != n && a[ai] == 0) {
                filelen++;
                ai++;
                ans.push_back(0);
                continue;
            }
            if (bi != m && b[bi] == 0) {
                filelen++;
                bi++;
                ans.push_back(0);
                continue;
            }
            char ch;
            if (ai != n && bi != m) {
                ch = a[ai] < b[bi] ? 'a' : 'b';
            } else if (ai != n) {
                ch = 'a';
            } else {
                ch = 'b';
            }

            if (ch == 'a') {
                if (a[ai] > filelen) {
                    failed = true;
                    break;
                }
                ans.push_back(a[ai]);
                ai++;
            } else {
                if (b[bi] > filelen) {
                    failed = true;
                    break;
                }
                ans.push_back(b[bi]);
                bi++;
            }
        }

        if (failed) {
            cout << -1 << endl;
        } else {
            for(int a : ans) {
                cout << a << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

