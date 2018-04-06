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

vector<char> chars;
set<char> inp;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  getline(cin, s);
  
  for( char ch : s ) {
    inp.insert(ch);
  }
  
  chars.push_back(' ');
  for( int i = '0'; i <= '9'; ++i ) {
    chars.push_back(i);
  }
  for( int i = 'A'; i <= 'Z'; ++i ) {
    chars.push_back(i);
  }
  for( int i = 'a'; i <= 'z'; ++i ) {
    chars.push_back(i);
  }
  chars.push_back('}');
  
  int last = -1;
  string ans1 = "%[";
  for( int i = 0; i < chars.size(); ++i ) {
    char ch = chars[i];
    if( (i == chars.size() - 1 || !inp.count(ch)) && last != -1 ) {
      string full;
      for( int j = last; j < i; ++j ) {
        full += chars[j];
      }
      string rng;
      if( last == 0 )
        rng += chars[last];
      else
        rng += chars[last-1] + 1;
      rng += '-';
      rng += chars[i-1];
      if( full.length() > rng.length() || (full.length() == rng.length() && full > rng) )
        swap(full, rng);
      
      ans1 += full;
      
      last = -1;
    } else if( inp.count(ch) && last == -1 ) {
      last = i;
    }
  }
  ans1 += "]";
  
  last = -1;
  string ans2 = "%[^";
  for( int i = 0; i < chars.size(); ++i ) {
    char ch = chars[i];
    if( (i == chars.size() - 1 || inp.count(ch)) && last != -1 ) {
      string full;
      for( int j = last; j < i; ++j ) {
        full += chars[j];
      }
      string rng;
      if( last == 0 )
        rng += chars[last];
      else
        rng += chars[last-1] + 1;
      rng += '-';
      rng += chars[i-1];
      if( full.length() > rng.length() || (full.length() == rng.length() && full > rng) )
        swap(full, rng);
      
      ans2 += full;
      
      last = -1;
    } else if( !inp.count(ch) && last == -1 ) {
      last = i;
    }
  }
  ans2 += "]";
  if( ans2.length() == 4 )
    ans2 = "%[^!]";
  
  if( ans1.length() > ans2.length() || (ans1.length() == ans2.length() && ans1 > ans2) )
    swap(ans1, ans2);
  
  cout << ans1 << "\n";
  
  return 0;
}
