#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

int fenwick[50][10000005];

inline void fastscan(int& number)
{
    bool negative = false;
    register int c;
    number = 0;
 
    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }
    
    while(!(c>47 && c<58))
      c = getchar();
 
    for (; (c>47 && c<58); c=getchar())
        number = number * 10 + c - 48;
 
    if (negative)
        number = -number;
}

int main() {
  int t;
  fastscan(t);
  for( int tc = 1; tc <= t; tc++ )
  {
    int n;
    fastscan(n);
    if( tc > 50 ) {
      memset(fenwick[tc], 0, sizeof(fenwick[tc]));
    }
    long long ans = 0;
    for( int i = 0; i < n; ++i ) {
      int k;
      fastscan(k);
      ans += i;
      register int ktmp = k;
      int* m = fenwick[tc % 50];
      for(; ktmp > 0; ktmp -= ktmp & -ktmp)
        ans -= m[ktmp];
      ktmp = k;
      for(; ktmp < 10000005; ktmp += ktmp & -ktmp)
        m[ktmp]++;
    }
    cout << ans << "\n";
  }
  return 0;
}