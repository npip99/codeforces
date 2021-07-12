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

bool lefties[(int)1e6];

void myswap(vector<int>& arr, int i, int j) {
    int b = max(i, j);
    int a = min(i, j);
    swap(arr[a], arr[b]);
    swap(lefties[a], lefties[b]);
    if ((b - a) % 2 == 1) {
        lefties[a] = !lefties[a];
        lefties[b] = !lefties[b];
    }
}

int partition(vector<int>& arr, int lo, int hi) {
    int pivot = arr[lo + rand() % (hi + 1 - lo)];

    int i = lo;
    int j = hi;

    while (true) {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if (i >= j) {
            return j;
        }
        myswap(arr, i, j);
        i++;
        j--;
    }
}

void quick_sort(vector<int>& arr, int lo = 0, int hi = -1) {
    if (hi == -1) {
        hi = arr.size() - 1;
    }
    if (lo < hi) {
        int pivot = partition(arr, lo, hi);
        quick_sort(arr, lo, pivot);
        quick_sort(arr, pivot + 1, hi);
    }
}

int main() {
    srand(2349238423);
    ios_base::sync_with_stdio(true);
    int T;
    cin >> T;
    for(int test = 0; test < T; test++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            lefties[i] = false;
        }
        quick_sort(a);
        bool bad = false;
        for(int i = 0; i < n; i++) {
            int even_lefties = 0;
            int odd_lefties = 0;

            int start = i;
            if (lefties[i]) {
                (i % 2 == 0 ? even_lefties : odd_lefties)++;
            }
            while(i+1 < n && a[start] == a[i+1]) {
                i++;
                if (lefties[i]) {
                    (i % 2 == 0 ? even_lefties : odd_lefties)++;
                }
            }

            // Even lefties can only cancel out odd lefties
            if (even_lefties != odd_lefties) {
                bad = true;
                break;
            }
        }
        if (bad == false) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
