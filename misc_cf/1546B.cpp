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
        int n, m;
        cin >> n >> m;
        vector<string> original(n);
        for(int i = 0; i < n; i++) {
            cin >> original[i];
        }
        vector<string> mixed(n-1);
        for(int i = 0; i < n-1; i++) {
            cin >> mixed[i];
        }
        string ans;
        for(int i = 0; i < m; i++) {
            map<char, int> original_freq;
            for(int j = 0; j < n; j++) {
                original_freq[original[j][i]]++;
            }
            map<char, int> mixed_freq;
            for(int j = 0; j < n-1; j++) {
                mixed_freq[mixed[j][i]]++;
            }
            for(char c = 'a'; c <= 'z'; c++) {
                if (original_freq[c] > mixed_freq[c]) {
                    ans += c;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
