#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>

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
  cin.tie(0);
  
  vi rob1(3);
  vi goal1(3);
  vi rob2(3);
  vi goal2(3);
  for( int i = 0; i < 3; ++i ) {
    cin >> rob1[i];
  }
  for( int i = 0; i < 3; ++i ) {
    cin >> goal1[i];
  }
  for( int i = 0; i < 3; ++i ) {
    cin >> rob2[i];
  }
  for( int i = 0; i < 3; ++i ) {
    cin >> goal2[i];
  }
  
  printf("(%i %i %i) (%i %i %i)\n", rob1[0], rob1[1], rob1[2], rob2[0], rob2[1], rob2[2]);
  while( rob1 != goal1 || rob2 != goal2 ) {
    int dir1, dir2;
    if( rob1 == goal1 )
      dir1 = -1;
    else
      dir1 = rand() % 3;
    if( rob2 == goal2 )
      dir2 = -1;
    else
      dir2 = rand() % 3;
    if( dir1 != -1 ) {
      while( rob1[dir1] == goal1[dir1] )
        dir1 = rand() % 3;
    }
    if( dir2 != -1 ) {
      while( rob2[dir2] == goal2[dir2] )
        dir2 = rand() % 3;
    }
    
    int diff1 = 0;
    int diff2 = 0;
    if( dir1 != -1 ) {
      if( rob1[dir1] > goal1[dir1] ) {
        diff1 = -1;
      } else if( rob1[dir1] < goal1[dir1] ) {
        diff1 = 1;
      }
    }
    if( dir2 != -1 ) {
      if( rob2[dir2] > goal2[dir2] ) {
        diff2 = -1;
      } else if( rob2[dir2] < goal2[dir2] ) {
        diff2 = 1;
      }
    }
    
    if( dir1 != -1 ) {
      rob1[dir1] += diff1;
      if( rob1 == rob2 ) {
        rob1[dir1] -= diff1;
        int newdir = dir1;
        while( newdir == dir1 )
          newdir = rand() % 3;
        rob1[newdir] += rand() % 2 == 0 ? -1 : 1;
      }
    }
    
    if( dir2 != -1 ) {
      rob2[dir2] += diff2;
      if( rob1 == rob2 ) {
        rob2[dir2] -= diff2;
        int newdir = dir2;
        while( newdir == dir2 )
          newdir = rand() % 3;
        rob2[newdir] += rand() % 2 == 0 ? -1 : 1;
      }
    }
    
    printf("(%i %i %i) (%i %i %i)\n", rob1[0], rob1[1], rob1[2], rob2[0], rob2[1], rob2[2]);
  }
  
  return 0;
}
