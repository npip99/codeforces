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
        int ax, ay, bx, by, fx, fy;
	cin >> ax >> ay >> bx >> by >> fx >> fy;
        int ans = abs(bx - ax) + abs(by - ay);
        // They are all colinear along the x,
        // and fy is in-between them,
        if (ax == bx && ax == fx && fy < max(ay, by) && min(ay, by) < fy) {
            ans += 2;
        }
        if (ay == by && ay == fy && fx < max(ax, bx) && min(ax, bx) < fx) {
            ans += 2;
        }
        cout << ans << endl;
    }
    return 0;
}

