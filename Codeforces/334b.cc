#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

void print (multiset<int> s){

  for (multiset<int>::iterator it = s.begin(); it != s.end(); it++){
    cout << *it << ' ';
  }
  cout << endl;
}

int main(){
  
  int n, k;
  cin >> n >> k;
  vector<int> v (n);
 
  multiset<int> s; 
  int m = 0;
  for (int i=0; i<n; i++){
    cin >> v[i];
    m = max (m, v[i]);
  }
  
  sort (v.begin(), v.end());
  
  
  while (k){
    if (v.size() == 0) break;
    
    s.insert (v.back());
    v.pop_back();
    k--;
  }
   
  for (int i=v.size()-1; i>= 0; i--){
    int aux = *s.begin();
    s.erase (s.begin());
    m = max (m, aux+v[i]);
  }
  
  cout << m << endl;
  return 0;
}
