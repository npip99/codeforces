#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef pair<pair<double, double>, int> pt;

vector<pt> points;

double cx[205];
double cy[205];
double cr[205];

int main() {
  cout.precision(12);
  
  double pi = 2*acos(0);
  
  int n;
  cin >> n;
  
  for( int i = 0; i < n; i++ ) {
    cin >> cx[i] >> cy[i] >> cr[i];
    cr[i] += 10;
  }
  
  points.reserve(n*n);
  
  pt best;
  bool found = false;
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < n; ++j ) {
      if( i == j )
        continue;
      double dist = sqrt((cx[i] - cx[j])*(cx[i] - cx[j]) + (cy[i] - cy[j])*(cy[i] - cy[j]));
      double angle = asin((cr[j] - cr[i])/dist) + pi/2;
      double incl = atan2(cy[j] - cy[i], cx[j] - cx[i]);
      double th1 = incl + angle;
      double th2 = incl - angle;
      pt p1 = pt({cx[i] + cr[i] * cos(th1), cy[i] + cr[i] * sin(th1)}, i);
      pt p2 = pt({cx[i] + cr[i] * cos(th2), cy[i] + cr[i] * sin(th2)}, i);
      bool inside = false;
      for( int k = 0; k < n; ++k ) {
        if( k == i )
          continue;
        if( (p1.first.first - cx[k])*(p1.first.first - cx[k])
            + (p1.first.second - cy[k])*(p1.first.second - cy[k]) <= cr[k]*cr[k] ) {
          inside = true;
          break;
        }
      }
      if( !inside ) {
        points.push_back(p1);
        if( !found || points.back().first < best.first ) {
          best = points.back();
          found = true;
        }
      }
      inside = false;
      for( int k = 0; k < n; ++k ) {
        if( k == i )
          continue;
        if( (p2.first.first - cx[k])*(p2.first.first - cx[k])
            + (p2.first.second - cy[k])*(p2.first.second - cy[k]) <= cr[k]*cr[k] ) {
          inside = true;
          break;
        }
      }
      if( !inside ) {
        points.push_back(p2);
        if( !found || points.back().first < best.first ) {
          best = points.back();
          found = true;
        }
      }
    }
  }
  
  if( points.size() == 0 ) {
    cout << 2*pi*cr[0] << endl;
    return 0;
  }
  
  sort(points.begin(), points.end(), [best](pt& a, pt& b) -> bool {
    double x1 = a.first.first - best.first.first;
    double y1 = a.first.second - best.first.second;
    double x2 = b.first.first - best.first.first;
    double y2 = b.first.second - best.first.second;
    
    if( x1*y2 - x2*y1 == 0 )
      return x2*x2+y2*y2 > x1*x1+y1*y1;
    else
      return x1*y2 - x2*y1 > 0;
  });
  
  vector<pt> convex;
  
  convex.push_back(points[0]);
  convex.push_back(points[1]);
  
  for( int i = 2; i < points.size(); i++ ) {
    while( true ) {
      double x1 = points[i].first.first - convex[convex.size()-2].first.first;
      double y1 = points[i].first.second - convex[convex.size()-2].first.second;
      double x2 = convex.back().first.first - convex[convex.size()-2].first.first;
      double y2 = convex.back().first.second - convex[convex.size()-2].first.second;
      
      if( x1*y2 - x2*y1 > 0 ) {
        convex.pop_back();
      } else {
        break;
      }
    }
    
    convex.push_back(points[i]);
  }
  
  double ans = 0;
  for( int i = 0; i < convex.size(); i++ ) {
    pt prev = convex[(i == 0) ? convex.size() - 1 : (i-1)];
    pt cur = convex[i];
    if( prev.second == cur.second ) {
      double x1 = prev.first.first - cx[prev.second];
      double y1 = prev.first.second - cy[prev.second];
      double x2 = cur.first.first - cx[cur.second];
      double y2 = cur.first.second - cy[cur.second];
      double angle = atan2(y2, x2) - atan2(y1, x1);
      if( angle >= 2*pi )
        angle -= 2*pi;
      if( angle < 0 )
        angle += 2*pi;
      ans += cr[prev.second]*angle;
    } else {
      ans += sqrt((prev.first.first - cur.first.first)*(prev.first.first - cur.first.first) +
                  (prev.first.second - cur.first.second)*(prev.first.second - cur.first.second));
    }
  }
  cout << ans << endl;
}