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
#define TEST_CASES false

void main_ans(int test_case) {
    int n;
    cin >> n;

    vector<int> possible_xs;

    for(int i = 1; i < n; i++) {
        possible_xs.push_back(i);
    }

    while(possible_xs.size() > 1) {
        int best_guess = -1;
        int best_min_freq;

        for(int guess = 1; guess < n; guess++) {
            unordered_map<int, int> freq;
            for(int a : possible_xs) {
                int new_x = a + guess;
                int return_val = new_x / n;

                freq[return_val]++;
            }

            int min_freq = -1;
            for(auto& kv : freq) {
                min_freq = min_freq == -1 ? kv.second : min(min_freq, kv.second);
            }

            if (best_guess == -1 || (best_min_freq < min_freq && freq.size() > 1)) {
                best_guess = guess;
                best_min_freq = freq.size() > 1 ? min_freq : -1;
            }
        }

        cout << "+ " << best_guess << endl;

        int result;
        cin >> result;

        vector<int> new_possible_xs;
        for(int a : possible_xs) {
            int new_x = a + best_guess;
            int return_val = new_x / n;

            if (return_val == result) {
                new_possible_xs.push_back(new_x);
            }
        }

        possible_xs = new_possible_xs;
    }

    cout << "! " << possible_xs[0] << endl;
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
