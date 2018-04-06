#include <iostream>

using namespace std;

int arr[200005];

typedef long long ll;

// [left, mid] and [mid+1, right] must be sorted
ll merge(int left, int mid, int right) {
  static int buf[200005];
  int buflen = 0;
  int l = left;
  int r = mid+1;
  ll ret = 0;
  while( l <= mid && r <= right ) {
    if( arr[l] > arr[r] ) {
      buf[buflen++] = arr[r++];
      ret += mid - l + 1;
    } else {
      buf[buflen++] = arr[l++];
    }
  }
  while( l <= mid ) {
    buf[buflen++] = arr[l++];
  }
  while( r <= right ) {
    buf[buflen++] = arr[r++];
  }
  // buflen = right - left + 1
  for( int i = 0; i < buflen; ++i ) {
    arr[i+left] = buf[i];
  }
  return ret;
}

ll inv(int left, int right) {
  if( right - left + 1 <= 43 ) {
    int k = right - left + 1;
    int ret = 0;
    for( int i = 0; i < k; ++i ) {
      for( int j = i + 1; j < k; ++j ) {
        if( arr[left+i] > arr[left+j] ) {
          ret++;
          swap(arr[left+i], arr[left+j]);
        }
      }
    }
    return ret;
  }
  
  if( left == right )
    return 0;
  int mid = (left+right)/2;
  return inv(left, mid) + inv(mid+1, right) + merge(left, mid, right);
}

int main() {
  int t;
  cin >> t;
  for( int tc = 1; tc <= t; tc++ )
  {
    int n;
    cin >> n;
    for( int i = 0; i < n; ++i ) {
      cin >> arr[i];
    }
    cout << inv(0, n-1) << "\n";
  }
}