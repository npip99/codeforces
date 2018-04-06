#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
  vector<int> myarr(5);
  myarr[3] = 2;
  
  set<int> myset;
  myset.insert(1);
  myset.count(1) == 1;
  myset.count(5) == 0;
  
  
}