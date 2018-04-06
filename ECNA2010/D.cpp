#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>



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
#define PI 3.14159265

int n,x,y,f;
int a[101][2];
double k[101];
int b[101];
int o[101];

bool cmp(int x, int y) {
  if (b[x] == b[y]) return (k[x] < k[y]);
  return b[x] < b[y];
}

bool isin(int p, int q) {
  double t1=atan2(a[p][1],a[p][0])*180/PI;
  double t2=atan2(a[q][1],a[q][0])*180/PI;
  if(t2<t1) t2+=360;
  return t2-t1 <=f;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  scanf("%d%d%d%d",&n,&x,&y,&f);
  int count = 0;
  while (n!=0)
  {
    count++;
    for (int i = 0; i < n; i++) {
      o[i] = i;
    }
    for(int i=0; i<n; i++)
    {
      int p,q;
      scanf("%d%d",&p,&q);
      a[i][0] = p - x;
      a[i][1] = q - y;
      if (a[i][0] > 0 && a[i][1] >= 0) b[i] = 1;
      if (a[i][0] <= 0 && a[i][1] > 0) b[i] = 2;
      if (a[i][0] < 0 && a[i][1] <= 0) b[i] = 3;
      if (a[i][0] >= 0 && a[i][1] < 0) b[i] = 4;    
      if (a[i][0] == 0)
        k[i]= -1010;
      else
        k[i] = (double)a[i][1] / (double)a[i][0];
    }
    sort(o, o+n, cmp);
    int minn = 101;
    for (int i = 0; i < n; i++) {
      int num = 1;
      int first = i;
      for (int j = 1; j < n; j++) {
        if (!isin(o[first], o[(i + j) % n])) {
          num++;
          first = (i + j) % n;
        }
        if (num > minn) break;
      }
      if (num < minn) minn = num;
    }
    printf("Case %d: %d\n", count, minn);
    scanf("%d%d%d%d",&n,&x,&y,&f);
  }
  return 0;
}
