#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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

string name[6];
int a[6];
int wintime[6];
int OT[6];
int goal[6];
int begoal[6];
int score[6];

int ff[5][5];

void compare2(int index[])
{
  if(ff[index[1]][index[2]]==0)
  {
    int i=index[1];
    int j=index[2];
    swap(score[i],score[j]);
    swap(name[i], name[j]);
    swap(wintime[i],wintime[j]);
    swap(OT[i],OT[j]);
    swap(goal[i],goal[j]);
    swap(begoal[i],begoal[j]);
    for(int k=1; k<=4; k++)
    {
      swap(ff[i][k],ff[j][k]);
      swap(ff[k][i],ff[k][j]);
    }
  }
}

void stepcompare(int index[], int num, int step)
{
  if(step == 1)
  {
    if(num == 2)
    {
      
    }
  }
  else if(step == 2)
  {
    
  }
  else if(step == 3)
  {
    
  }
  else if(step == 4)
  {
    
  }
  else
  {
    if(num == 2)
    {
      compare2(index);
    }
  }
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a,b;
  name[1]="Russia";
  name[2]="Sweden";
  name[3]="NA";
  name[4]="Finland";
  for(int i=0; i<5; i++)
  {
    int p,q;
    if(a == "OT")
    {
      cin>>a>>b;
      cin>>p>>q;
    }
    else
    {
      cin>>b;
      cin>>p>>q;
    }
    cin>>a;
    int f=0;
    if(a=="OT") f=1;
    int x,y;
    for(int j=1; j<=4; j++)
    {
      if(a == name[j])
      {
        x=j;
        if(p>q) 
        {
          wintime[j]++;
          score[j]+=2;
        }
        if(f==1) 
        {
          if(p<q) score[j]++;
          OT[j]++;
        }
        goal[j]+=p;
        begoal[j]+=q;
      }
      if(b == name[j])
      {
        y=j;
        if(p<q) 
        {
          wintime[j]++;
          score[j]+=2;
        }
        if(f==1) 
        {
          if(p>q) score[j]++;
          OT[j]++;
        }
        goal[j]+=q;
        begoal[j]+=p;
      }
    }
    if(p>q) ff[p][q] = 1;
    if(q>p) ff[q][p] = 1;
  }
  for(int i=1; i<=3; i++)
  for(int j=i; j<=4; j++)
  {
    if(score[i]<score[j])
    {
      swap(score[i],score[j]);
      swap(name[i], name[j]);
      swap(wintime[i],wintime[j]);
      swap(OT[i],OT[j]);
      swap(goal[i],goal[j]);
      swap(begoal[i],begoal[j]);
      for(int k=1; k<=4; k++)
      {
        swap(ff[i][k],ff[j][k]);
        swap(ff[k][i],ff[k][j]);
      }
    }
  }
  
  if(score[1] == score[2] && score[2]!=score[3])
  {
    if(ff[1][2]==0)
    {
      int i=1;
      int j=2;
      swap(score[i],score[j]);
      swap(name[i], name[j]);
      swap(wintime[i],wintime[j]);
      swap(OT[i],OT[j]);
      swap(goal[i],goal[j]);

      for(int k=1; k<=4; k++)
      {
        swap(ff[i][k],ff[j][k]);
        swap(ff[k][i],ff[k][j]);
      }
    }
  }
  if(score[2]==score[3] && score[3]!=score[4] && score[2]!=score[1])
  {
    if(ff[2][3]==0)
    {
      int i=2;
      int j=3;
      swap(score[i],score[j]);
      swap(name[i], name[j]);
      swap(wintime[i],wintime[j]);
      swap(OT[i],OT[j]);
      swap(goal[i],goal[j]);
      swap(begoal[i],begoal[j]);
      for(int k=1; k<=4; k++)
      {
        swap(ff[i][k],ff[j][k]);
        swap(ff[k][i],ff[k][j]);
      }
    }
  }
  if(score[3]==score[4] && score[3]!=score[2])
  {
    if(ff[3][4]==0)
    {
      int i=3;
      int j=4;
      swap(score[i],score[j]);
      swap(name[i], name[j]);
      swap(wintime[i],wintime[j]);
      swap(OT[i],OT[j]);
      swap(goal[i],goal[j]);
      swap(begoal[i],begoal[j]);
      for(int k=1; k<=4; k++)
      {
        swap(ff[i][k],ff[j][k]);
        swap(ff[k][i],ff[k][j]);
      }
    }
  }
  
  if(score[1]==score[2] && score[2]==score[3] && score[3]==score[4])
  {
    for(int i=1; i<=3; i++)
    for(int j=i; j<=4; j++)
    {
      if(wintime[i]<wintime[j])
      {
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
    }
    if(wintime[1] == wintime[2])
    if(wintime[1] == wintime[2] && wintime[2]!=wintime[3])
    {
      if(wintime[1]-OT[1]<wintime[2]-OT[2])
      {
        int i=1;
        int j=2;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
      else if(wintime[1]-OT[1] == wintime[2]-OT[2] && goal[1]-begoal[1]<goal[2]-begoal[2])
      {
        int i=1;
        int j=2;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
      else if(wintime[1]-OT[1] == wintime[2]-OT[2] && goal[1]-begoal[1] == goal[2]-begoal[2] && goal[1]<goal[2])
      {
        int i=1;
        int j=2;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
      else if(wintime[1]-OT[1] == wintime[2]-OT[2] && goal[1]-begoal[1] == goal[2]-begoal[2] && goal[1]==goal[2] && ff[1][2]==0)
      {
        int i=1;
        int j=2;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
    }
    if(wintime[2] == wintime[3] && wintime[3]!=wintime[4])
    {
      if(wintime[2]-OT[2]<wintime[3]-OT[3])
      {
        int i=2;
        int j=3;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
      else if(wintime[2]-OT[2] == wintime[3]-OT[3] && goal[2]-begoal[2]<goal[3]-begoal[3])
      {
        int i=2;
        int j=3;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
      else if(wintime[2]-OT[2] == wintime[3]-OT[3] && goal[2]-begoal[2] == goal[3]-begoal[3] && goal[2]<goal[3])
      {
        int i=2;
        int j=3;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
      else if(wintime[2]-OT[2] == wintime[3]-OT[3] && goal[2]-begoal[2] == goal[3]-begoal[3] && goal[2]==goal[3] && ff[2][3]==0)
      {
        int i=2;
        int j=3;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
    }
    if(wintime[3] == wintime[4] && wintime[3]!=wintime[4])
    {
      if(wintime[3]-OT[3]<wintime[4]-OT[4])
      {
        int i=3;
        int j=4;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
      else if(wintime[3]-OT[3] == wintime[4]-OT[4] && goal[3]-begoal[3]<goal[4]-begoal[4])
      {
        int i=3;
        int j=4;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
      else if(wintime[3]-OT[3] == wintime[4]-OT[4] && goal[3]-begoal[3] == goal[4]-begoal[4] && goal[3]<goal[4])
      {
        int i=3;
        int j=4;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
      else if(wintime[3]-OT[3] == wintime[4]-OT[4] && goal[3]-begoal[3] == goal[4]-begoal[4] && goal[3]==goal[4] && ff[3][4]==0)
      {
        int i=3;
        int j=4;
        swap(score[i],score[j]);
        swap(name[i], name[j]);
        swap(wintime[i],wintime[j]);
        swap(OT[i],OT[j]);
        swap(goal[i],goal[j]);
        swap(begoal[i],begoal[j]);
        for(int k=1; k<=4; k++)
        {
          swap(ff[i][k],ff[j][k]);
          swap(ff[k][i],ff[k][j]);
        }
      }
    }
  }
  else if(score[1]==score[2] && score[2]==score[3] && score[3]!=score[4])
  {
    
  }
  else if(score[1]!=score[2] && score[2]==score[3] && score[3]==score[4])
  {
    
  }
  
  cin>>a>>b;
  int x,y;
  for(int i=1; i<=4; i++)
  {
    if(a == name[i]) x=i;
    if(b == name[i]) y=i;
  }
  
  return 0;
}
