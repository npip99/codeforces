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
        int n;
        cin >> n;
        vector<int> a(n);
        int asum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            asum += a[i];
        }
        vector<int> b(n);
        int bsum = 0;
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            bsum += b[i];
        }
        if (asum == bsum) {
            vector<ii> ans;
            for(int i = 0; i < n; i++) {
                // Redistribute to fix a[i]
                for(int j = i+1; j < n; j++) {
                    while(a[i] < b[i] && a[j] > b[j]) {
                        a[j]--;
                        a[i]++;
                        ans.push_back({j, i});
                    }
                    while(a[i] > b[i] && a[j] < b[j]) {
                        a[i]--;
                        a[j]++;
                        ans.push_back({i, j});
                    }
                }
            }
            cout << ans.size() << endl;
            for(ii sans : ans) {
                cout << get<0>(sans)+1 << " " << get<1>(sans)+1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}

