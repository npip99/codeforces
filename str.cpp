#include <iostream>

using namespace std;

char strings[1000][500];
int hashes[1000][500];
int buckets[10000][1000];
int bucketsz[10000];

int cinvpow[1001];
int cpow[1001];

int main()
{
  int n, l;
  cin >> n >> l;
  
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < l; ++j ) {
      cin >> strings[i][j];
    }
  }
  
  int mod = 9973;
  int c = 9967;
  int cinv = 0;
  
  while( (c * cinv) % mod != 1 )
    cinv++;
  
  cpow[0] = 1;
  cinvpow[0] = 1;
  for( int i = 1; i <= n; ++i ) {
    cinvpow[i] = (cinv * cinvpow[i-1]) % mod;
    cpow[i] = (c * cpow[i-1]) % mod;
  }
  
  for( int i = 0; i < n; ++i ) {
    hashes[i][0] = strings[i][0] % mod;
    for( int j = 1; j < l; ++j ) {
      hashes[i][j] = (hashes[i][j-1] + cpow[j] * strings[i][j]) % mod;
    }
  }
  
  for( int a = 0; a < l; ++a ) {
    for( int b = a + 1; b < l; ++b ) {
      for( int i = 0; i < mod; ++i ) {
        bucketsz[i] = 0;
      }
      for( int i = 0; i < n; ++i ) {
        int h = hashes[i][b];
        if( a != 0 )
          h -= hashes[i][a-1];
        h *= cinvpow[a];
        h %= mod;
        buckets[h][bucketsz[h]++] = i;
      }
      for( int i = 0; i < mod; ++i ) {
        if( bucketsz[i] > 1 ) {
          bool dif = 
          for( int x = 0; x < bucketsz[i]; ++x ) {
            for( int y = x + 1; y < bucketsz[i]; ++y ) {
            }
          }
        }
      }
    }
  }
}