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
  
  int n, k;
  cin >> n >> k;
  vi arr(n);
  for( int i = 0; i < n; ++i ) {
    cin >> arr[i];
  }
  
  vi secs;
  int curtype = 1;
  int curnum = 0;
  for( int i = 0; i < n; ++i ) {
    if( arr[i] == curtype ) {
      curnum++;
    } else {
      curtype = 1 - curtype;
      secs.push_back(curnum);
      curnum = 1;
    }
  }
  secs.push_back(curnum);
  if( curtype == 0 ) {
    secs.push_back(0);
  }
  
  vi prefix1;
  vi prefix0;
  for( int i = 0; i < secs.size(); i += 2 ) {
    prefix1.push_back(secs[i]);
    if( prefix1.size() >= 2 ) {
      prefix1.back() += prefix1[prefix1.size()-2];
    }
  }
  for( int i = 1; i < secs.size(); i += 2 ) {
    prefix0.push_back(secs[i]);
    if( prefix0.size() >= 2 ) {
      prefix0.back() += prefix0[prefix0.size()-2];
    }
  }
  
  for( int left = -1; left < secs.size(); left += 2 ) {
    int right = upper_bound(prefix0.begin(), prefix0.end(), left == -1 ? k : prefix0[left / 2] + k) - prefix0.begin();
    right = 2 * right + 1;
    int zrng = 0;
    if( left + 2 <= right - 2 ) {
      zrng = prefix0[right/2-1] - (left == -1 ? 0 : prefix0[left/2]);
    }
    int vl = 0;
    if( left > 0 && zrng < k ) {
      vl += min(secs[left], k - zrng);
      zrng += vl;
    }
    int vr = 0;
    if( right < secs.size() && zrng < k ) {
      vr += min(secs[right], k - zrng);
    }
  }
  
  /*
  for(int k : secs) {
    cout << k << endl;
  }
  
  vi prefix1;
  vi prefix0;
  for( int i = 0; i < secs.size(); i += 2 ) {
    prefix1.push_back(secs[i]);
    if( prefix1.size() >= 2 ) {
      prefix1.back() += prefix1[prefix1.size()-2];
    }
  }
  for( int i = 1; i < secs.size(); i += 2 ) {
    prefix0.push_back(secs[i]);
    if( prefix0.size() >= 2 ) {
      prefix0.back() += prefix0[prefix0.size()-2];
    }
  }
  
  int ans = *max(prefix1.begin(), prefix1.end());
  for( int i = 0; i < prefix0.size(); i++ ) {
    int ind = upper_bound(prefix0.begin(), prefix0.end(), (i == 0 ? 0 : prefix0[i-1]) + k) - prefix0.begin();
    int rng = prefix1[ind];
    if( i > 0 )
      rng -= prefix1[i-1];
    int zeroes = ind == prefix0.size() ? prefix0[ind-1] : prefix0[ind];
    zeroes -= i - 2 < 0 ? 0 : prefix0[i-2];
    zeroes = min(zeroes, k);
    ans = max(ans, rng + zeroes);
  }
  
  for( int i = 0; i < prefix0.size(); i++ ) {
    int ind = upper_bound(prefix0.begin(), prefix0.end(), (i == 0 ? 0 : prefix0[i-1]) + k) - prefix0.begin();
    int rng = prefix1[ind];
    if( i > 0 )
      rng -= prefix1[i-1];
    int right = ind == prefix0.size() ? prefix0[ind-1] : prefix0[ind];
    right -= prefix0[ind-1];
    int zeroes = prefix0[ind-1];
    zeroes -= i < 1 ? 0 : prefix0[i-1];
    right = max(right, zeroes - k);
    int left = i < 1 ? 0 : prefix0[i-1];
    if( i > 1 )
      left -= prefix0[i-2];
    left = max(left, zeroes - right - k);
    if( ans == rng + left + zeroes + right ) {
      for( int j = 0; j < secs.size(); j++ ) {
        if( j % 2 == 0 ) {
          for(int k = 0; k < secs[j]; k++)
            cout << "1 ";
        } else {
          for(int k = 0; k < secs[j]; k++) {
            if( left > 0 && i-1 == (j / 2) ) {
              if(k < secs[j] - left){
                cout << "0 ";
              } else {
                cout << "1 ";
              }
            } else if( right > 0 && ind == (j/2) ) {
              if(k < right) {
                cout << "1 ";
              } else {
                cout << "0 ";
              }
            } else if( i - 1 < j/2 && j/2 < ind ) {
              cout << "1 ";
            } else {
              cout << "0 ";
            }
          }
        }
      }
      break;
    }
  }*/
  
  
  return 0;
}
