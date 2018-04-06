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

#define mn 200005

long double arr[mn];
long double prob[mn];
long double answers[mn];
bool isplus[mn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  for( int i = 0; i < 2*n; ++i ) {
    char ch;
    cin >> ch >> arr[i];
    isplus[i] = ch == '+';
  }
  
  int numplus = 0;
  int oldi = 0;
  for( int i = 0; i < 2*n; ++i ) {
    if( isplus[i] )
      numplus++;
    else {
      prob[i] = 1.0 / numplus;
      numplus--;
      
      if(numplus == 0) {        
        long double sum = 0;
        int numans = 0;
        for( int j = i; j >= oldi; --j ) {
          if( isplus[j] ) {
            answers[numans++] = sum - arr[j];
          } else {
            sum = prob[j] * arr[j] + (1-prob[j]) * sum;
          }
        }
        
        for( int i = numans - 1; i >= 0; --i ) {
          cout << answers[i] << "\n";
        }
        
        oldi = i+1;
      }
    }
  }
  
  
  return 0;
}
