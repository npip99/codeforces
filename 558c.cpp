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

#define N 100005

int arr[N]; // input
int got[2*N]; // # of elems that can get to i
ll steps[2*N]; // # of steps it takes, for all a_i to reach i

int main()
{
  ios::sync_with_stdio(false);
  cout.precision(12);
  cin.tie(0);
  
  int n;
  cin >> n;
  for( int i = 0; i < n; ++i ) {
    cin >> arr[i];
  }
  
  int vis[2*N];
  for( int j = 0; j < 2*N; ++j ) {
    vis[j] = -1;
  }
  for( int i = 0; i < n; ++i ) {
    int k = arr[i];
    ll step = 0;
    while( k > 0 ) {
      vis[k] = i;
      steps[k] += step;
      got[k]++;
      
      int newk = 2 * k;
      int newstep = step + 1;
      if( vis[newk] != i ) {
        while( newk < 2*N ) {
          steps[newk] += newstep;
          got[newk]++;
          vis[newk] = i;
          newk *= 2;
          newstep++;
        }
      }
      
      k /= 2;
      step++;  
    }
  }
  
  ll best = steps[1];
  for( int i = 2; i < 2*N; ++i ) {
    if( got[i] == n ) {
      best = min(best, steps[i]);
    }
  }
  
  cout << best << "\n";
  
  return 0;
}
