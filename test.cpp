#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

#define sz 1000000

int arr[sz];

int main()
{
  std::srand ( unsigned ( std::time(0) ) );
  
  for( int i = 0; i < sz; i++ )
    arr[i] = i;
  int tot = 0;
  for( int i = 0; i < 100; i++ ) {
    random_shuffle(arr, arr+sz);
    int ans = 0;
    for( int i = 0; i < sz; i++ )
      if( arr[i] == i )
        ans++;
    tot += ans;
    cout << ans << endl;
  }
  
  cout << tot << endl;
  
  return 0;
}
