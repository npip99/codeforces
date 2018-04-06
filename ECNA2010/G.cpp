#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>



using namespace std;

int v,o,m;
int a[10001][2];
char n[111][111];

int main()
{
  scanf("%d%d%d",&v,&o,&m);
  int count=0;
  for(int i=0; i<101; i++)
     for(int j=0; j<101; j++)
      n[i][j]=' ';
  while(!(v==0 && o==0 && m==0))
  {
    count++;
    printf("Case %d:\n",count);
    for(int i=0; i<v; i++)
    {
      scanf("%d%d",&a[i][0],&a[i][1]);
    }
    for(int i=0; i<o; i++)
    {
      int p,q;
      scanf("%d%d",&p,&q);
      n[p][q] = 'M';
    }
    for(int i=0; i<m; i++)
    {
      char c;
      cin >> c;
      int x1,y1,x2,y2;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      if(x1>x2) swap(x1,x2);
      if(y1>y2) swap(y1,y2);
      for(int j=x1; j<=x2; j++)
        for(int k=y1; k<=y2; k++)
          n[j][k]=c;
    }
    int f=0;
    for(int i=0; i<v; i++)
    {
      int h=0;
      int t=0;
      //cout<<a[i][0]<<' '<<a[i][1]<<endl;
      //cout<<n[4][1]<<endl;
      for(int j=a[i][0]; j<=100; j++)
      {
        if(n[j][a[i][1]]=='W')
        {
          t=1;
          break;
        }
        if(n[j][a[i][1]]!=' ') break;
      }
      if(t==1)
      {
        h=1;
        printf("vampire %d east",i+1);
      }
      t=0;
      for(int j=a[i][1]; j<=100; j++)
      {
        if(n[a[i][0]][j]=='M') break;
        if(n[a[i][0]][j]=='S')
        {
          t=1;
          break;
        }
        if(n[a[i][0]][j]!=' ') break;
      }
      if(t==1 && h==0)
      {
        h=1;
        printf("vampire %d north",i+1);
      }
      else if(t==1) printf(" north");
      t=0;
      for(int j=a[i][1]; j>=0; j--)
      {
        if(n[a[i][0]][j]=='M') break;
        if(n[a[i][0]][j]=='N')
        {
          t=1;
          break;
        }
        if(n[a[i][0]][j]!=' ') break;
      }
      if(t==1 && h==0)
      {
        h=1;
        printf("vampire %d south",i+1);
      }
      else if(t==1) printf(" south");
      t=0;
      for(int j=a[i][0]; j>=0; j--)
      {
        if(n[j][a[i][1]]=='M') break;
        if(n[j][a[i][1]]=='E')
        {
          t=1;
          break;
        }
        if(n[j][a[i][1]]!=' ') break;
      }
      if(t==1 && h==0)
      {
        h=1;
        printf("vampire %d west",i+1);
      }
      else if(t==1) printf(" west");
      
      if(h==1) 
      {
        printf("\n");
        f=1;
      }
      
    }
    if(f==0) printf("none\n");
    scanf("%d%d%d",&v,&o,&m);
    for(int i=0; i<101; i++)
       for(int j=0; j<101; j++)
        n[i][j]=' ';
  }
}