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

int main()
{
  int t;
  cin >> t;

  for(int tt = 0; tt < t; tt++) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> st;
    string ans = "YES\n";
    for(int i = 0; i < n; i++) {
      char c = s[i];
      // If a new character is one we've already done
      if (st.count(c) && (i > 0 && s[i-1] != c)) {
        ans = "NO\n";
        break;
      }
      st.insert(c);
    }
    cout << ans;
  }

  return 0;
}
