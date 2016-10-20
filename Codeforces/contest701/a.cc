#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main (){

  int n;
  cin >>n;
  vector<pair<int, int> > v;
  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back (make_pair (a, i+1));
  }
  
  sort(v.begin(), v.end());
  
  int i = 0;
  int j = v.size() - 1;
  
  while (i < j){
    cout << v[i].second << ' ' << v[j].second << endl;
    i++;
    j--;
  }
  return 0;
}
