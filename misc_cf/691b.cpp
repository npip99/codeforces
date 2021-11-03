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
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<string, string> mss;

#define err(x) cerr << #x << " = " << (x) << endl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL
#define mod int(1e9+7)

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  string s;
  cin >> s;
  
  string ssym = "AHIMOoTUVvWwXxY";
  set<char> sym;
  for( char c : ssym ) {
    sym.insert(c);
  }
  
  int len = s.length();
  bool works = true;
  for( int i = 0; i <= len/2; i++ ) {
    bool bd =  (s[i] == 'b' && s[len-1-i] == 'd') || (s[i] == 'd' && s[len-1-i] == 'b');
    bool pq = (s[i] == 'p' && s[len-1-i] == 'q') || (s[i] == 'q' && s[len-1-i] == 'p');
    works &= (sym.count(s[i]) && s[i] == s[len-1-i]) || bd || pq;
  }
  
  cout << (works ? "TAK\n" : "NIE\n");
  
  return 0;
}
