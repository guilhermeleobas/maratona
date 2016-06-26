#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main (){
  
  int n, m, k;
  cin >> n >> m >> k;
  
  vector<int> v (k);
  
  for (int i=0; i<k; i++)
    cin >> v[i];
  
  int sum = 0;
  
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      int aux;
      cin >> aux;
      int pos = find (begin(v), end(v), aux) - begin(v);
      sum += pos+1;
      v.erase (begin(v) + pos);
      v.insert (begin(v), aux);
    }
  }
  
  cout << sum << endl;
  
  return 0;
}
