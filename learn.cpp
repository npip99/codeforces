#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cassert>

using namespace std;

int main() {
  //***********************
  // std::vector<>
  //***********************

  // Initialize an array consisting of 5 1's
  vector<int> myarr(5, 1);
  assert(myarr[0] == 1);

  // Set myarr[3] = 2
  myarr[3] = 2;
  // Push 4 onto the end(back) of the array
  myarr.push_back(4);

  assert(myarr.size() == 6);
  assert(myarr[5] == 4);

  //***********************
  // std::set<>
  //***********************

  set<int> myset;
  myset.insert(1);
  // Measures the number of occurances of an element (For sets, only 0 or 1 is possible)
  assert(myset.count(1) == 1);
  assert(myset.count(5) == 0);

  //***********************
  // std::map<>
  //***********************
  map<int, char> m;
  m[2] = 'a';
  // 2 -> 'a' is the only mapping in the map
  assert(m.count(2) == 1);
  assert(m[2] == 'a');
  assert(m.size() == 1);
  // 100 is not in the map
  assert(m.count(100) == 0);
  // Simply accessing an element fills it with a default value of 0
  assert(m[100] == '\0');
  // Which effectively adds it to the map
  assert(m.count(100) == 1);
  assert(m.size() == 2);
  // Use count, to check if something is a member of a map,
  // without actually putting it in the map by accident
}
