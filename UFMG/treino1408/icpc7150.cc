// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=5162


#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

bool comp (pair<int, int> a, pair<int, int> b){
  if (a.first > b.first){
    return false;
  }
  
  // [..., a, ..., b, ...]
  return a.second < b.second;
}

void print (vector<pair<int, int> > arr){
  for (int i=0; i<arr.size(); i++){
    cout << arr[i].first << ' ' << arr[i].second << endl;
  }
  cout << endl;
}

int main (){
 
  while (true){
   
    int p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;
    if (not cin) break;
    
    vector<double> v (n);
    
    for (int i=1; i<=n; i++){
      v[i-1] = p * (sin(a*i + b) + cos(c*i + d) + 2); 
    }
  
    double maior = v[0];
    double diff = 0.0;
    
    bool status = false;
    
    for (int i=1; i<n; i++){
      if (maior < v[i]){
        maior = v[i];
      }
      
      if (diff < maior - v[i]){
        diff = maior - v[i];
        status = true;
      }
      
    }
    
    if (status){
      cout << fixed << setprecision (6) << diff << endl;
    }
    else {
      cout << "0.00" << endl;
    }
  }
  return 0;
}
