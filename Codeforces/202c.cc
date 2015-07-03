#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long acc = 0;

bool valid (vector<int> &v, long long mid){
  long long acc = 0;
  for (int i=0; i<v.size(); i++){
    acc += mid - v[i];
    if (mid < v[i])
      return false;
  }
  return acc >= mid;
}

long long bsearch (vector<int> &v){
  long long l = 0, r = 100000000000000;
  // [l, r)
  while (r > l){
    long long mid = (l + r)/2;
    
//    cout << l << ' ' << r << ' ' << valid (v, l) << ' ' << valid (v, r) << endl;
    if (valid (v, mid)){
      r = mid;
    }
    else {
      l = mid+1;
    }
  }

  return r;
}

int main (){

  int n;
  cin >> n;

  vector<int> v(n);

  for (int i=0; i<n; i++)
    cin >> v[i];

  cout << bsearch (v) << endl;

  return 0;
}
